#!/bin/sh

NS_GLOBAL_VALUE="RngRun=1" ./waf --run "scratch/lte-tcp-high-speed --packetSize=1400 --p2pDelay=0 --bufferSize=80000" &
NS_GLOBAL_VALUE="RngRun=1" ./waf --run "scratch/lte-tcp-high-speed --packetSize=14000 --p2pDelay=0 --bufferSize=80000" &
NS_GLOBAL_VALUE="RngRun=1" ./waf --run "scratch/lte-tcp-high-speed --packetSize=1400 --p2pDelay=18 --bufferSize=200000" &
NS_GLOBAL_VALUE="RngRun=1" ./waf --run "scratch/lte-tcp-high-speed --packetSize=14000 --p2pDelay=18 --bufferSize=200000" &

wait
echo all processes done