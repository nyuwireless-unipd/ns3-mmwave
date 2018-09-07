# -*- Mode: python; py-indent-offset: 4; indent-tabs-mode: nil; coding: utf-8; -*-

# def options(opt):
#     pass

# def configure(conf):
#     conf.check_nonfatal(header_name='stdint.h', define_name='HAVE_STDINT_H')

def build(bld):
    module = bld.create_ns3_module('mmwave', ['core','network', 'spectrum', 'virtual-net-device','point-to-point','applications','internet', 'lte', 'propagation'])
    module.source = [
        'helper/mmwave-helper.cc',
        'helper/mmwave-phy-rx-trace.cc',
        'helper/mmwave-point-to-point-epc-helper.cc',
        'helper/mmwave-bearer-stats-calculator.cc',
        'helper/mmwave-bearer-stats-connector.cc',
        'helper/mc-stats-calculator.cc',
        'helper/core-network-stats-calculator.cc',
        'model/mmwave-net-device.cc',
        'model/mmwave-enb-net-device.cc',
        'model/mmwave-ue-net-device.cc',
        'model/mmwave-phy.cc',
        'model/mmwave-enb-phy.cc',
        'model/mmwave-ue-phy.cc',
        'model/mmwave-spectrum-phy.cc',
        'model/mmwave-spectrum-value-helper.cc',
        'model/mmwave-beamforming.cc',
        'model/mmwave-interference.cc',
        'model/mmwave-chunk-processor.cc',
        'model/mmwave-mac.cc',
        'model/mmwave-mac-scheduler.cc',
        'model/mmwave-control-messages.cc',
        'model/mmwave-spectrum-signal-parameters.cc',
        'model/mmwave-radio-bearer-tag.cc',
        'model/mmwave-amc.cc',
        'model/mmwave-phy-mac-common.cc',
        'model/mmwave-mac-sched-sap.cc',
        'model/mmwave-mac-csched-sap.cc',
        'model/mmwave-phy-sap.cc',
        'model/mmwave-mi-error-model.cc',
        'model/mmwave-enb-mac.cc',
        'model/mmwave-ue-mac.cc',
        'model/mmwave-rrc-protocol-ideal.cc',
        'model/mmwave-lte-rrc-protocol-real.cc',
        'model/mmwave-channel-matrix.cc',
		'model/buildings-obstacle-propagation-loss-model.cc',
        'model/mmwave-mac-pdu-header.cc',
        'model/mmwave-mac-pdu-tag.cc',
        'model/mmwave-harq-phy.cc',
        'model/mmwave-flex-tti-mac-scheduler.cc',
        'model/mmwave-flex-tti-maxweight-mac-scheduler.cc',
        'model/mmwave-flex-tti-maxrate-mac-scheduler.cc',
        'model/mmwave-flex-tti-pf-mac-scheduler.cc',
        'model/mmwave-propagation-loss-model.cc',
        'model/antenna-array-model.cc',
        'model/mmwave-channel-raytracing.cc',
        'model/mc-ue-net-device.cc',
        'model/mmwave-los-tracker.cc',
        'model/mmwave-3gpp-propagation-loss-model.cc',
        'model/mmwave-3gpp-channel.cc',
        'model/mmwave-3gpp-buildings-propagation-loss-model.cc',
        'model/mmwave-component-carrier.cc',
        'model/mmwave-component-carrier-ue.cc',
        'model/mmwave-component-carrier-enb.cc',
        'model/mmwave-no-op-component-carrier-manager.cc'
        #'model/mmwave-enb-cmac-sap.cc',
        #'model/mmwave-enb-rrc.cc',
        #'model/mmwave-mac-sap.cc',
        #'model/mmwave-rrc-sap.cc',
        #'model/mmwave-rlc.cc',
        #'model/mmwave-rlc-sap.cc'
        ]

    module_test = bld.create_ns3_module_test_library('mmwave')
    module_test.source = [
        #'mmwave-test-suite.cc'
        ]

    headers = bld(features='ns3header')
    headers.module = 'mmwave'
    headers.source = [
        'helper/mmwave-helper.h',
        'helper/mmwave-phy-rx-trace.h',
        'helper/mmwave-point-to-point-epc-helper.h',
        'helper/mmwave-bearer-stats-calculator.h',
        'helper/mc-stats-calculator.h',
        'helper/core-network-stats-calculator.h',
        'helper/mmwave-bearer-stats-connector.h',
        'model/mmwave-net-device.h',
        'model/mmwave-enb-net-device.h',
        'model/mmwave-ue-net-device.h',
        'model/mmwave-phy.h',
        'model/mmwave-enb-phy.h',
        'model/mmwave-ue-phy.h',
        'model/mmwave-spectrum-phy.h',
        'model/mmwave-spectrum-value-helper.h',
        'model/mmwave-beamforming.h',
        'model/mmwave-interference.h',
        'model/mmwave-chunk-processor.h',
        'model/mmwave-mac.h',
        'model/mmwave-phy-mac-common.h',
        'model/mmwave-mac-scheduler.h',
        'model/mmwave-control-messages.h',
        'model/mmwave-spectrum-signal-parameters.h',
        'model/mmwave-radio-bearer-tag.h',
        'model/mmwave-amc.h',
        'model/mmwave-mac-sched-sap.h',
        'model/mmwave-mac-csched-sap.h',
        'model/mmwave-phy-sap.h',
        'model/mmwave-mi-error-model.h',
        'model/mmwave-enb-mac.h',
        'model/mmwave-ue-mac.h',
        'model/mmwave-rrc-protocol-ideal.h',
        'model/mmwave-lte-rrc-protocol-real.h',
        'model/mmwave-channel-matrix.h',
		'model/buildings-obstacle-propagation-loss-model.h',
        'model/mmwave-mac-pdu-header.h',
        'model/mmwave-mac-pdu-tag.h',
        'model/mmwave-harq-phy.h',
        'model/mmwave-flex-tti-mac-scheduler.h',
        'model/mmwave-flex-tti-maxweight-mac-scheduler.h',
        'model/mmwave-flex-tti-maxrate-mac-scheduler.h',
        'model/mmwave-flex-tti-pf-mac-scheduler.h',
        'model/mmwave-propagation-loss-model.h',
        'model/antenna-array-model.h',
        'model/mmwave-channel-raytracing.h',
        'model/mc-ue-net-device.h',
        'model/mmwave-los-tracker.h' ,
        'model/mmwave-3gpp-propagation-loss-model.h',
        'model/mmwave-3gpp-channel.h',
        'model/mmwave-3gpp-buildings-propagation-loss-model.h',
        'model/mmwave-component-carrier.h',
        'model/mmwave-component-carrier-ue.h',
        'model/mmwave-component-carrier-enb.h',
        'model/mmwave-no-op-component-carrier-manager.h'
        #'model/mmwave-enb-cmac-sap.h',
        #'model/mmwave-enb-rrc.h',
        #'model/mmwave-mac-sap.h',
        #'model/mmwave-rrc-sap.h',
        #'model/mmwave-rlc.h',
        #'model/mmwave-rlc-sap.h'
        ]

    if bld.env.ENABLE_EXAMPLES:
        bld.recurse('examples')

    bld.ns3_python_bindings()
