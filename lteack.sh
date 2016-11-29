#! /bin/bash

# first input parAM is the number of simulations for each combination
# second input parAM is the first run number
# third input parAM a boolean: true=fast switching, false=hard handover
# fourth input parAM a boolean: true=filter, false=original SINR
# fifth input parAM is handover mode: 1 for threshold, 2 for fixed, 3 for dynamic
# sixth input parAM a boolean: true=udp 20 us, false=tcp

fs=1
filter=1
hoMode=3
udp=0


pwd

if [ $fs -eq 1 ]
then
	dlP="mcDlPdcp*"
	ulP="mcUlPdcp*"
	dlR="mcDlRlc*"
	ulR="mcUlRlc*"
	x2="mcX2Stats_*"
else
	dlP="hhDlPdcp*"
	ulP="hhUlPdcp*"
	dlR="hhDlRlc*"
	ulR="hhUlRlc*"
	x2="hhX2Stats_*"
fi
# AM cycle

reportTablePeriodicity=1600

mkdir -p "../simulations_tcp/onlyLteAck/udp$udp/"
mkdir -p "../simulations_tcp/onlyLteAck/udp$udp/filter$filter/hoMode$hoMode/"

# cycle on app data rate
for bufferSize in 2
do
	mkdir -p "../simulations_tcp/onlyLteAck/udp$udp/filter$filter/hoMode$hoMode/bufferSize$bufferSize"
	# cycle on x2Latency
	for ueSpeed in 2 5 
	do
		outPath="../simulations_tcp/onlyLteAck/udp$udp/filter$filter/hoMode$hoMode/bufferSize$bufferSize/ueSpeed$ueSpeed/"
		mkdir -p "$outPath"
		echo
		echo "udp $udp filter $filter hoMode $hoMode bufferSize $bufferSize reportTablePeriodicity $reportTablePeriodicity outPath $outPath"
		date
		rn=$2
		for i in $(seq 1 $1)
		do
			echo -e "$(date +"%T")\t"
			echo -e "Simulation run $rn\n"
			./waf --run "scratch/mc-onebs --mobileSpeed=$ueSpeed --lteUplink=true --noiseAndFilter=$filter --handoverMode=$hoMode --reportTablePeriodicity=$reportTablePeriodicity --udp=$udp --fastSwitching=$fs --bufferSize=$bufferSize --interPckInterval=80 --runNumber=$rn --outPath=$outPath" > "$outPath$3simOut$rn.txt" 2>&1
			rn=$((rn+1))
		done
		echo -e "Simulations completed"
		echo -e "Start analysis"
		perl pdcpFilter.pl ../simulations_tcp/onlyLteAck/udp$udp/filter$filter/hoMode$hoMode/bufferSize$bufferSize/ueSpeed$ueSpeed $fs

		if [ $? -eq 0 ]
		then
			rm $outPath$dlP
			rm $outPath$ulP
			rm $outPath$dlR
			rm $outPath$ulR
			rm $outPath$x2
		else
			echo "Not deleted"
		fi
	done	
done

# AM cycle
