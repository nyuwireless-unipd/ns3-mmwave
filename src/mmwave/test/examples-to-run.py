#! /usr/bin/env python
# -*- coding: utf-8 -*-
## -*- Mode: python; py-indent-offset: 4; indent-tabs-mode: nil; coding: utf-8; -*-

# A list of C++ examples to run in order to ensure that they remain
# buildable and runnable over time.  Each tuple in the list contains
#
#     (example_name, do_run, do_valgrind_run).
#
# See test.py for more information.
cpp_examples = [
    ("mc-twoenbs-ipv6", "True", "True"),
    ("mc-twoenbs", "True", "True"),
    ("mmwave-amc-test", "True", "True"),
    ("mmwave-amc-test2", "True", "True"),
    ("mmwave-ca-diff-bandwidth", "True", "True"),
    ("mmwave-ca-same-bandwidth", "True", "True"),
    ("mmwave-epc-amc-test", "True", "True"),
    ("mmwave-epc-tdma", "True", "True"),
    ("mmwave-example", "True", "True"),
    ("mmwave-simple-building-obstacle", "True", "True"),
    ("mmwave-simple-epc-ipv6", "True", "True"),
    ("mmwave-simple-epc", "True", "True"),
    ("mmwave-tcp-building-example", "True", "True"),
    ("mmwave-tcp-example", "True", "True"),
    ("mmwave-tdma", "True", "True"),
]

# A list of Python examples to run in order to ensure that they remain
# runnable over time.  Each tuple in the list contains
#
#     (example_name, do_run).
#
# See test.py for more information.
python_examples = []
