# -*- Mode: python; py-indent-offset: 4; indent-tabs-mode: nil; coding: utf-8; -*-

# def options(opt):
#     pass

# def configure(conf):
#     conf.check_nonfatal(header_name='stdint.h', define_name='HAVE_STDINT_H')

def build(bld):
    module = bld.create_ns3_module('mmwave-energy', ['core', 'energy', 'mmwave'])
    module.source = [
        'model/mmwave-energy.cc',
        'helper/mmwave-energy-helper.cc',
        ]

    module_test = bld.create_ns3_module_test_library('mmwave-energy')
    module_test.source = [
        'test/mmwave-energy-test-suite.cc',
        ]

    headers = bld(features='ns3header')
    headers.module = 'mmwave-energy'
    headers.source = [
        'model/mmwave-energy.h',
        'helper/mmwave-energy-helper.h',
        ]

    if bld.env.ENABLE_EXAMPLES:
        bld.recurse('examples')

    # bld.ns3_python_bindings()

