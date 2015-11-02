
#ifdef NS3_MODULE_COMPILATION
# error "Do not include ns3 module aggregator headers from other modules; these are meant only for end user scripts."
#endif

#ifndef NS3_MODULE_WAVE
    

// Module headers:
#include "bsm-application.h"
#include "channel-coordinator.h"
#include "channel-manager.h"
#include "channel-scheduler.h"
#include "default-channel-scheduler.h"
#include "higher-tx-tag.h"
#include "ocb-wifi-mac.h"
#include "vendor-specific-action.h"
#include "vsa-manager.h"
#include "wave-bsm-helper.h"
#include "wave-bsm-stats.h"
#include "wave-helper.h"
#include "wave-mac-helper.h"
#include "wave-mac-low.h"
#include "wave-net-device.h"
#include "wifi-80211p-helper.h"
#endif
