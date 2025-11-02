# CRITICAL BUG: Data Plane Not Switching on Second Handover

## Problem Summary

After handover from cell 2 to cell 3 at t=10.66s, the **data plane (S1-U path) does NOT switch** to cell 3. User data continues to flow through cell 2 even though the control plane shows UE is connected to cell 3.

## Evidence

### First Handover (t=1.29s): ✅ WORKS

```
[S1-U-AUTO] 1.291s: New handover detected to cell 2 - starting auto-detection timer
[S1-U-DEBUG] 1.291-1.491s: Using temporary X2 forwarding
[S1-U-AUTO] 1.541s: AUTO-SWITCHING to direct S1-U (200ms timeout reached)
[S1-U-CORE] 1.541s: *** TRIGGERING S1AP PATH SWITCH ***
[S1-U-CORE] 1.541s: *** S1AP PATH SWITCH COMPLETED ***
[S1-U] 1.541s: *** OPTIMIZED *** Using direct S1-U after handover to cell 2
```

### Second Handover (t=10.66s): ❌ BROKEN

```
+10.659800000s targetCellId = 3
+10.660300001s Setup remote RLC in cell 3
+10.663017856s Received RRC connection reconf completed on cell 3
+10.663017856s Imsi 1 m_mmWaveCellSetupCompleted set to true for cell 3
```

**NO S1-U messages!** No path switch, no auto-detection, nothing!

## Impact

### Control Plane vs Data Plane Mismatch

After t=10.66s:
- **Control plane**: UE connected to cell 3 ✓
- **Data plane**: Packets still routed through cell 2 ✗

This causes:
1. **Suboptimal routing**: Data goes through wrong cell
2. **Higher latency**: Extra X2 forwarding from cell 2 to cell 3
3. **Increased X2 load**: All user data forwarded over X2
4. **Poor performance**: UE is far from cell 2 (561m at t=20s)

### Data Path at t=20s

```
Internet → SGW/PGW → Cell 2 (0m) --X2--> Cell 3 (600m) → UE (561m)
                      ^^^^^^^                              ^^^^^^^^^
                      561m away!                      Close by (39m)
```

Should be:
```
Internet → SGW/PGW → Cell 3 (600m) → UE (561m)
                      ^^^^^^^        ^^^^^^^^^
                      Close by!      (39m away)
```

## Root Cause

The S1-U path switch logic is **not detecting** the second handover. Possible causes:

### 1. One-Time Detection Logic

The S1-U auto-detection may only work for the FIRST handover and not reset for subsequent handovers.

### 2. State Not Reset

After first handover completes, some state variable may not be reset, preventing second handover from triggering S1-U path switch.

### 3. Cell 2→3 Handover Not Recognized

The logic may only handle LTE→mmWave handover, not mmWave→mmWave handover.

### 4. Missing Hook in Handover Completion

The handover completion callback that triggers S1-U path switch may not be called for secondary cell handovers.

## Where to Investigate

### Check S1-U Path Switch Code

Location: `src/lte/model/epc-x2.cc` or similar

Look for:
- Handover detection logic
- State variables that track handover status
- Conditions that trigger S1-U path switch

### Check Handover Completion Callbacks

Location: `src/lte/model/lte-enb-rrc.cc`

Look for:
- `DoRecvSecondaryCellHandoverCompleted`
- Where S1-U path switch should be triggered
- Why it's not calling the path switch logic

### Check First vs Second Handover Difference

Compare:
- First handover: LTE (cell 1) → mmWave (cell 2)
- Second handover: mmWave (cell 2) → mmWave (cell 3)

The S1-U logic may only handle the first type!

## Immediate Action Required

This is a **CRITICAL BUG** that needs to be fixed. The handover is functionally incomplete - control plane switches but data plane doesn't!

### Temporary Workaround

None - this requires code fix.

### Fix Strategy

1. Find where S1-U path switch is triggered for first handover
2. Ensure same trigger fires for mmWave→mmWave handovers
3. Add logging to track S1-U state through multiple handovers
4. Test that data plane switches correctly

## Test Plan

After fix:
1. Run same simulation
2. Verify S1-U path switch messages appear for BOTH handovers:
   - First: LTE→mmWave (cell 2) at t=1.29s
   - Second: mmWave→mmWave (cell 2→3) at t=10.66s
3. Confirm data flows through correct cell after each handover
4. Check X2 forwarding is removed after path switch completes
