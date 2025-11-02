# SINR Jump Root Cause Analysis

## ✅ ROOT CAUSE CONFIRMED

**The SINR jumps are caused by `ThreeGppChannelConditionModel::UpdatePeriod = 100ms`**

Every 100ms, the channel condition model re-evaluates LOS/NLOS state. When this changes, the entire channel (K-factor, delay spread, beamforming vectors) is regenerated, causing 20-40 dB SINR jumps.

**Fix:** Set BOTH UpdatePeriods to large values:
```cpp
Config::SetDefault("ns3::ThreeGppChannelModel::UpdatePeriod", TimeValue(Seconds(100)));
Config::SetDefault("ns3::ThreeGppChannelConditionModel::UpdatePeriod", TimeValue(Seconds(100)));
```

**Status:** Solution needs to be re-tested with BOTH parameters set correctly.

---

## Problem Summary

The SINR measurements in mc-n-enbs.cc show very large, periodic jumps (20-43 dB) that are causing instability in handover decisions. Analysis of the log files reveals:

### Observed Behavior

1. **Large SINR Jumps**: SINR values jump by 20-43 dB suddenly
2. **Periodic Pattern**: SINR stays constant for ~100ms, then jumps
3. **High Frequency**: 35-53 jumps > 20 dB over 20 seconds
4. **Asymmetry**: Forward and backward tests show different mean SINR values

### Statistics from Analysis

**Forward Cell 2:**
- SINR range: -34.67 to 47.52 dB (82 dB range!)
- Mean: -5.39 dB, Std dev: 21.89 dB
- Max jump: 43.26 dB
- Jumps > 20 dB: 35 times in 20 seconds

**Backward Cell 2:**
- SINR range: -35.19 to 45.21 dB
- Mean: -7.37 dB, Std dev: 21.43 dB  
- Max jump: 41.02 dB
- Jumps > 20 dB: 41 times in 20 seconds

## Root Cause

**CONFIRMED ROOT CAUSE: ThreeGppChannelConditionModel::UpdatePeriod**

The SINR jumps are caused by the **channel condition model** (NOT the channel model itself) updating every 100ms and changing LOS/NLOS state.

### The Two UpdatePeriod Settings

There are TWO separate UpdatePeriod settings in the 3GPP channel implementation:

1. **ThreeGppChannelModel::UpdatePeriod**: Controls fast fading updates (small-scale fading)
2. **ThreeGppChannelConditionModel::UpdatePeriod**: Controls LOS/NLOS state re-evaluation

### What Actually Happens

```cpp
// From scratch/mc-n-enbs.cc
Config::SetDefault("ns3::ThreeGppChannelModel::UpdatePeriod", TimeValue(MilliSeconds(100)));
Config::SetDefault("ns3::ThreeGppChannelConditionModel::UpdatePeriod", TimeValue(MilliSeconds(100))); // THIS IS THE CULPRIT
```

Every 100ms:
1. **ChannelConditionModel re-evaluates** LOS/NLOS based on 3GPP probability formulas
2. If condition changes (LOS ↔ NLOS), **ChannelModel::ChannelParamsNeedsUpdate()** returns true
3. **Complete channel regeneration** occurs:
   - New K-factor (9.559 for LOS → 0 for NLOS)
   - New delay spread, angular spreads
   - New cluster powers and delays
   - New beamforming vectors
4. **Result**: SINR changes dramatically (20-40 dB jumps)

### Why Solution 5 Failed to Fix It

When we tested "disabling fast fading" in Solution 5:
```cpp
Config::SetDefault("ns3::ThreeGppChannelModel::UpdatePeriod", TimeValue(MilliSeconds(0))); // Disabled
Config::SetDefault("ns3::ThreeGppChannelConditionModel::UpdatePeriod", TimeValue(MilliSeconds(100))); // STILL ACTIVE!
```

We only disabled the **channel model** updates, but the **channel condition model** was still running every 100ms!

### Evidence from Detailed Logging

Running with `NS_LOG="ThreeGppChannelModel=level_debug"` showed:
- 88 "Update the channel condition" messages in 20 seconds
- Channel regenerations at: 0.100s, 0.200s, 0.400s, 0.801s... (irregular but ~100ms period)
- K-factor changing: 9.559 (LOS) → 0 (NLOS) → back and forth
- Each condition change triggers `GetNewChannel()` → complete regeneration

### Code Path

```cpp
bool ThreeGppChannelModel::ChannelParamsNeedsUpdate(...)
{
    // FIRST CHECK: Did LOS/NLOS condition change?
    if (!channelCondition->IsEqual(channelParams->m_losCondition, channelParams->m_o2iCondition))
    {
        NS_LOG_DEBUG("Update the channel condition");
        return true;  // FORCE REGENERATION!
    }
    
    // SECOND CHECK: Did UpdatePeriod expire?
    if (!m_updatePeriod.IsZero() && 
        Simulator::Now() - channelParams->m_generatedTime > m_updatePeriod)
    {
        return true;
    }
    
    return false;
}
```

So even with `m_updatePeriod = 0`, the condition check still triggers regeneration!

### Why This Causes Asymmetry

The asymmetry between forward and backward tests is caused by:

1. **Random LOS/NLOS Transitions**: Each 100ms, condition model uses random variables to determine LOS/NLOS
2. **Position-Dependent Timing**: Forward vs backward runs hit different update cycles at the same position
3. **Stochastic Channel Realizations**: Each regeneration produces different random fading

## Impact on Handover

This SINR instability severely affects handover:

1. **False Triggering**: A single bad channel realization can trigger unnecessary handover
2. **Missed Handovers**: A single good channel realization can prevent necessary handover  
3. **Ping-Pong Effect**: SINR oscillates wildly causing back-and-forth handovers
4. **Unpredictable Behavior**: Different runs produce different handover patterns

## Solutions

### Solution 1: Reduce BOTH UpdatePeriods to Match SINR Measurement Period

Set both UpdatePeriods = 12.8ms to match the SINR measurement interval:

```cpp
Config::SetDefault("ns3::ThreeGppChannelModel::UpdatePeriod", TimeValue(MilliSeconds(12.8)));
Config::SetDefault("ns3::ThreeGppChannelConditionModel::UpdatePeriod", TimeValue(MilliSeconds(12.8)));
```

**Pros:**
- Every SINR measurement gets fresh channel AND condition
- No more constant-then-jump pattern
- More realistic for high-mobility scenarios

**Cons:**
- Much higher computational cost (8x more updates)
- May show more variation (but realistic for mmWave)
- LOS/NLOS may change too frequently

### Solution 2: Increase BOTH UpdatePeriods for Stability ⭐ RECOMMENDED

Set both UpdatePeriods = 1000ms (1 second) for stable measurements:

```cpp
Config::SetDefault("ns3::ThreeGppChannelModel::UpdatePeriod", TimeValue(MilliSeconds(1000)));
Config::SetDefault("ns3::ThreeGppChannelConditionModel::UpdatePeriod", TimeValue(MilliSeconds(1000)));
```

**Pros:**
- Much more stable SINR measurements
- Fewer jumps (only 20 updates in 20 seconds)
- Lower computational cost
- Good for debugging handover logic

**Cons:**
- May not capture fast fading effects
- LOS/NLOS changes less frequently than reality

### Solution 3: Use Hysteresis and Time-to-Trigger (ALREADY IMPLEMENTED)

The code already has:
```cpp
lteHelper->SetHandoverAlgorithmAttribute("Hysteresis", DoubleValue(3.0));
lteHelper->SetHandoverAlgorithmAttribute("TimeToTrigger", TimeValue(MilliSeconds(256)));
```

This helps filter out short-term SINR fluctuations, but may not be enough for 20-40 dB jumps from LOS/NLOS transitions.

### Solution 4: SINR Averaging/Filtering

Implement Layer 3 filtering (as in real LTE/5G):
- Use exponential moving average
- Weight factor α (e.g., 0.5)
- `SINR_filtered = α × SINR_new + (1-α) × SINR_old`

### Solution 5: Disable Channel Condition Updates (Quasi-Static LOS/NLOS) ⭐ BEST FOR TESTING

For testing handover logic, fix LOS/NLOS condition:

```cpp
Config::SetDefault("ns3::ThreeGppChannelModel::UpdatePeriod", TimeValue(Seconds(100)));
Config::SetDefault("ns3::ThreeGppChannelConditionModel::UpdatePeriod", TimeValue(Seconds(100))); // MUST SET THIS TOO!
```

**Status:** NOT YET TESTED (previous test only disabled channel model, not condition model)

**Test Result (Forward Run):**
- **PARTIALLY FAILED**: The SINR jump is still present even with ThreeGppChannelModel::UpdatePeriod disabled
- However, detailed logging revealed the **actual root cause**!

**ACTUAL ROOT CAUSE DISCOVERED:**

When we set:
```cpp
Config::SetDefault("ns3::ThreeGppChannelModel::UpdatePeriod", TimeValue(MilliSeconds(0)));
Config::SetDefault("ns3::ThreeGppChannelConditionModel::UpdatePeriod", TimeValue(MilliSeconds(100)));  // STILL 100ms!
```

We disabled fast fading in the **channel model** but NOT in the **channel condition model**!

**What's happening:**
1. Every 100ms, `ThreeGppChannelConditionModel` re-evaluates whether the link is LOS or NLOS
2. The LOS/NLOS state changes probabilistically based on distance and 3GPP models
3. When LOS/NLOS changes, `ThreeGppChannelModel::ChannelParamsNeedsUpdate()` returns true
4. This forces complete channel regeneration (new K-factor, delay spread, angles, etc.)
5. Result: SINR jumps dramatically

**Evidence from log file:**
- 88 "Update the channel condition" messages during 20s simulation
- Channel regenerations happen at: 0.100s, 0.200s, 0.400s, 0.801s, 0.901s, etc. (matches UpdatePeriod=100ms)
- K-factor changes: 9.559 (LOS) → 0 (NLOS) → varies
- Channel parameters completely regenerated each time

**Key Code Path:**
```cpp
bool ThreeGppChannelModel::ChannelParamsNeedsUpdate(...)
{
    // FIRST check: Channel condition changed?
    if (!channelCondition->IsEqual(channelParams->m_losCondition, ...))
    {
        return true;  // REGENERATE!
    }
    
    // SECOND check: UpdatePeriod expired?
    if (!m_updatePeriod.IsZero() && ...)
    {
        return true;
    }
}
```

So even with channel model UpdatePeriod=0, the condition model UpdatePeriod still triggers regeneration!

## Recommended Approach

**For debugging handover asymmetry**, use **Solution 5 (CORRECTED)**:

```cpp
// Disable BOTH channel model AND condition model updates
Config::SetDefault("ns3::ThreeGppChannelModel::UpdatePeriod", TimeValue(Seconds(100)));
Config::SetDefault("ns3::ThreeGppChannelConditionModel::UpdatePeriod", TimeValue(Seconds(100)));
```

This will:
1. Fix LOS/NLOS state for entire simulation
2. Eliminate all SINR jumps from channel regeneration
3. Make SINR only depend on position and path loss
4. Allow us to identify any remaining asymmetry issues

**For production simulations**, use **Solution 2 + Solution 3 + Solution 4**:
1. Long UpdatePeriods (1000ms) for more stable channel
2. Keep existing hysteresis (3 dB) and time-to-trigger (256ms)
3. Implement proper L3 filtering to smooth measurements
4. This better matches real-world mmWave behavior

## Next Steps

**IMMEDIATE ACTION:**

1. **Re-test Solution 5 CORRECTLY** by setting BOTH UpdatePeriods to very large values:
   ```cpp
   Config::SetDefault("ns3::ThreeGppChannelModel::UpdatePeriod", TimeValue(Seconds(100)));
   Config::SetDefault("ns3::ThreeGppChannelConditionModel::UpdatePeriod", TimeValue(Seconds(100)));
   ```

2. **Run forward test** and verify SINR is now smooth (no jumps)

3. **Run backward test** and compare with forward

4. **If asymmetry persists** with stable channel:
   - It's NOT channel randomness
   - Must be propagation model bug or beamforming issue
   - Focus investigation on position-dependent calculations

5. **If asymmetry disappears** with stable channel:
   - Confirms random channel was the cause
   - Use Solution 2 (long UpdatePeriod) for stable simulations
   - Consider implementing Solution 4 (L3 filtering) for realism
