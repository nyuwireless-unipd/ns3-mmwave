# SINR Jump Root Cause - CONFIRMED! 🎯

## The Problem
SINR measurements show dramatic jumps (20-40 dB) every ~100ms, causing unstable handover decisions.

## The Root Cause (CONFIRMED)

**ThreeGppChannelConditionModel::UpdatePeriod = 100ms**

### What We Discovered

There are TWO separate UpdatePeriod parameters:

1. **ThreeGppChannelModel::UpdatePeriod** - Controls fast fading (small-scale fading)
2. **ThreeGppChannelConditionModel::UpdatePeriod** - Controls LOS/NLOS state updates

### The Problem

Every 100ms:
- Channel **condition** model re-evaluates if link is LOS or NLOS
- When condition changes (LOS ↔ NLOS), channel model detects this
- Triggers COMPLETE channel regeneration:
  - K-factor changes: 9.559 (LOS) → 0 (NLOS)
  - New delay spread, angular spreads
  - New beamforming vectors
  - Result: 20-40 dB SINR jump!

### Why "Disabling Fast Fading" Didn't Work

In Solution 5, we only disabled the channel model:
```cpp
Config::SetDefault("ns3::ThreeGppChannelModel::UpdatePeriod", TimeValue(MilliSeconds(0)));
Config::SetDefault("ns3::ThreeGppChannelConditionModel::UpdatePeriod", TimeValue(MilliSeconds(100))); // STILL RUNNING!
```

The condition model was still updating every 100ms!

### The Evidence

From detailed logging (`NS_LOG="ThreeGppChannelModel=level_debug"`):
- 88 "Update the channel condition" messages in 20 seconds
- K-factor oscillating: 9.559 → 0 → 9.559 → 0 ...
- Channel regenerations at: 0.100s, 0.200s, 0.400s, 0.801s, 0.901s...
- Each matches a condition change

### The Code Path

```cpp
bool ThreeGppChannelModel::ChannelParamsNeedsUpdate(...)
{
    // FIRST: Check if LOS/NLOS changed
    if (!channelCondition->IsEqual(...))
    {
        NS_LOG_DEBUG("Update the channel condition");
        return true;  // REGENERATE EVERYTHING!
    }
    
    // SECOND: Check if UpdatePeriod expired
    if (!m_updatePeriod.IsZero() && ...)
    {
        return true;
    }
}
```

So even with channel model UpdatePeriod = 0, the condition check triggers regeneration!

## The Solution

### For Debugging (Recommended)

Disable BOTH update periods:
```cpp
Config::SetDefault("ns3::ThreeGppChannelModel::UpdatePeriod", TimeValue(Seconds(100)));
Config::SetDefault("ns3::ThreeGppChannelConditionModel::UpdatePeriod", TimeValue(Seconds(100)));
```

This freezes LOS/NLOS state and eliminates all channel randomness.

### For Stable Simulations

Use longer periods:
```cpp
Config::SetDefault("ns3::ThreeGppChannelModel::UpdatePeriod", TimeValue(MilliSeconds(1000)));
Config::SetDefault("ns3::ThreeGppChannelConditionModel::UpdatePeriod", TimeValue(MilliSeconds(1000)));
```

### For Realistic Simulations

Match SINR measurement period + implement L3 filtering:
```cpp
Config::SetDefault("ns3::ThreeGppChannelModel::UpdatePeriod", TimeValue(MilliSeconds(12.8)));
Config::SetDefault("ns3::ThreeGppChannelConditionModel::UpdatePeriod", TimeValue(MilliSeconds(12.8)));
// + Add exponential moving average filtering in RRC layer
```

## Next Steps

1. ✅ Root cause confirmed through detailed logging
2. 🔄 Need to re-test with BOTH UpdatePeriods set correctly
3. ⏭️ Then check if asymmetry persists with stable channel
4. ⏭️ If asymmetry remains → investigate propagation/beamforming bugs
5. ⏭️ If asymmetry disappears → it was just random channel variations

## Files Updated

- `SINR_JUMP_ROOT_CAUSE.md` - Complete analysis with all details
- `ROOT_CAUSE_SUMMARY.md` - This file (quick reference)

## Key Insight

The ns-3 3GPP channel model has **two separate update mechanisms**:
- Channel parameters (fading)
- Channel conditions (LOS/NLOS)

Both must be controlled to get stable/predictable SINR measurements!
