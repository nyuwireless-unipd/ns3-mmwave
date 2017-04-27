#!/bin/bash

# run an endless loop and launch ns-3 simulations

echo -e "NYU mmWave module\n"
pwd

rm *.txt
rm -r trace

./waf --run "scratch/mmwave-tcp-indoor --protocol=TcpNewReno --bufferSize=10000000"
mkdir NewReno10Mb
mv *.txt NewReno10Mb/

./waf --run "scratch/mmwave-tcp-indoor --protocol=TcpVegas --bufferSize=10000000"
mkdir TcpVegas10Mb
mv *.txt TcpVegas10Mb/

./waf --run "scratch/mmwave-tcp-indoor --protocol=TcpNewReno --bufferSize=5000000"
mkdir NewReno5Mb
mv *.txt NewReno5Mb/

./waf --run "scratch/mmwave-tcp-indoor --protocol=TcpVegas --bufferSize=5000000"
mkdir TcpVegas5Mb
mv *.txt TcpVegas5Mb/

./waf --run "scratch/mmwave-tcp-indoor --protocol=TcpNewReno --bufferSize=1000000"
mkdir NewReno1Mb
mv *.txt NewReno1Mb/

./waf --run "scratch/mmwave-tcp-indoor --protocol=TcpVegas --bufferSize=1000000"
mkdir TcpVegas1Mb
mv *.txt TcpVegas1Mb/


mkdir trace
mv *Mb trace
