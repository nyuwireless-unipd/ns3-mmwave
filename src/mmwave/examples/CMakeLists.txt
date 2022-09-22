set(base_examples
    mmwave-example
    mmwave-tcp-example
    mmwave-simple-epc
    mmwave-simple-epc-ipv6
    mmwave-epc-tdma
    mmwave-tdma
    mmwave-simple-building-obstacle
    mmwave-tcp-building-example
    mmwave-amc-test
    mmwave-amc-test2
    mmwave-epc-amc-test
    mc-twoenbs
    mc-twoenbs-ipv6
    mmwave-ca-same-bandwidth
    mmwave-ca-diff-bandwidth
    mmwave-beamforming-codebook-example
)

foreach(
  example
  ${base_examples}
)
  build_lib_example(
    NAME ${example}
    SOURCE_FILES ${example}.cc
    LIBRARIES_TO_LINK ${libmmwave}
  )
endforeach()

if(${ENABLE_QD_CHANNEL})
  build_lib_example(
    NAME qd-channel-full-stack-example
    SOURCE_FILES qd-channel-full-stack-example.cc
    LIBRARIES_TO_LINK
      ${libmmwave}
      ${libqd-channel}
  )
endif()
