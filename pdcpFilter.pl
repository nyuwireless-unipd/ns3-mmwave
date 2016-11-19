#!/usr/local/bin/perl
use File::Basename;
$num_args =$#ARGV + 1;
if($num_args != 2) {
	print "\nUsage: pdcpFilter.pl folder_name mc\n";
	exit;
}
$folder_name=$ARGV[0];
$mc=$ARGV[1];

$outpath = "./".$folder_name."/";

if($mc==1)
{
	# get a list of files matching DlPdcpStats
	my @filelist = glob($outpath."mcDlPdcpStats*");

	print $outpath."\n";

	$basefilename = "throughputDl_PdcpFilter.txt";
	#variables
	$sampling_time=0.05; #0.5s
	$app_start_time=0.5;

	#open out file
	open (MCSIMLIST, ">".$outpath."mcSimList.txt") or die "$! error trying to overwrite";
	# The original contents are gone, wave goodbye.

	for $path (@filelist) {
		print $path;
		print "\n";

		$file = basename($path);

		print $file;
		print "\n";

		my $version;
		my $date;
		if($file =~ /^mcDlPdcpStats_(\w*)/)
		{
			$version = "mc";
			$date = $1;
			print MCSIMLIST $date."\n";
		}
		else
		{
			warn "Invalid\n";
		}
		$outfilename = $outpath.$version.$date.$basefilename;
		print $outfilename."\n";

		#open log file, update log file name when needed
		open (LOGFILE, $path) or die "I couldn't get at log.txt";

		#open out file for downlink statistics
		open (DOWNLINK, ">".$outfilename) or die "$! error trying to overwrite";
	    # The original contents are gone, wave goodbye.

		$prev_time=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$rxBytes=0; #number of bytes received
		$delay=0;
		$num_pck=0;

		#downlink
		for $line (<LOGFILE>) {

			if($line =~ /^(.x)/) { #\s(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)/) {
		 		
				if($1 eq "Rx")
				{
					if($line =~ /(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)$/ )
					{
						if($1<=$prev_time) {
					 		$rxBytes+=$2;
					 		$delay+=$3;
					 		$num_pck+=1;
					 	}	
					 	else #update actual time, pkts, total delay and print throughput at that time
					 	{	
					 		if($num_pck > 0)
					 		{
						 		print DOWNLINK join("\t", ($prev_time, $rxBytes*8, $delay/$num_pck));
					 			print DOWNLINK "\n";
					 		}
					 		$rxBytes = $2;
					 		$delay = $3;	
					 		$num_pck=1;
					 		while($1 >= $prev_time)
					 		{
						 		$prev_time+=$sampling_time;
					 		}
						}
					}
				}
			}
			else
			{
				warn "Not usual pattern\n";
			}
		}

		close LOGFILE;
		close DOWNLINK;
	}

	## Uplink throughput

	# get a list of files matching DlPdcpStats
	my @filelist = glob($outpath."mcUlPdcpStats*");

	$basefilename = "throughputUl_PdcpFilter.txt";
	#variables
	$sampling_time=0.05; #0.5s
	$app_start_time=0.5;

	#open out file
	open (MCSIMLIST, ">".$outpath."mcSimList_up.txt") or die "$! error trying to overwrite";
	# The original contents are gone, wave goodbye.

	for $path (@filelist) {
		print $path;
		print "\n";

		$file = basename($path);

		print $file;
		print "\n";

		my $version;
		my $date;
		if($file =~ /^mcUlPdcpStats_(\w*)/)
		{
			$version = "mc";
			$date = $1;
			print MCSIMLIST $date."\n";
		}
		else
		{
			warn "Invalid\n";
		}
		$outfilename = $outpath.$version.$date.$basefilename;
		print $outfilename."\n";



		#open log file, update log file name when needed
		open (LOGFILE, $path) or die "I couldn't get at log.txt";

		#open out file for downlink statistics
		open (DOWNLINK, ">".$outfilename) or die "$! error trying to overwrite";
	    # The original contents are gone, wave goodbye.

		$prev_time=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$rxBytes=0; #number of bytes received
		$delay=0;
		$num_pck=0;

		#downlink
		for $line (<LOGFILE>) {

			if($line =~ /^(.x)/) { #\s(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)/) {
		 		
				if($1 eq "Rx")
				{
					if($line =~ /(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)$/ )
					{
						if($1<=$prev_time) {
					 		$rxBytes+=$2;
					 		$delay+=$3;
					 		$num_pck+=1;
					 	}	
					 	else #update actual time, pkts, total delay and print throughput at that time
					 	{	
					 		if($num_pck > 0)
					 		{
						 		print DOWNLINK join("\t", ($prev_time, $rxBytes*8, $delay/$num_pck));
					 			print DOWNLINK "\n";
					 		}
					 		$rxBytes = $2;
					 		$delay = $3;	
					 		$num_pck=1;
					 		while($1 >= $prev_time)
					 		{
						 		$prev_time+=$sampling_time;
					 		}
						}
					}
				}
			}
			else
			{
				warn "Not usual pattern\n";
			}
		}

		close LOGFILE;
		close DOWNLINK;
	}

	## RLC throughput

	my @filelist = glob($outpath."mcDlRlcStats*");

	$basefilename = "throughputDl_RlcFilter.txt";
	#variables
	$sampling_time=0.05; #0.5s
	$app_start_time=0.5;

	#open out file
	open (MCSIMLIST, ">".$outpath."mcSimList_rlcDl.txt") or die "$! error trying to overwrite";
	# The original contents are gone, wave goodbye.

	for $path (@filelist) {
		print $path;
		print "\n";

		$file = basename($path);

		print $file;
		print "\n";

		my $version;
		my $date;
		if($file =~ /^mcDlRlcStats_(\w*)/)
		{
			$version = "mc";
			$date = $1;
			print MCSIMLIST $date."\n";
		}
		else
		{
			warn "Invalid\n";
		}
		$outfilename = $outpath.$version.$date.$basefilename;
		print $outfilename."\n";



		#open log file, update log file name when needed
		open (LOGFILE, $path) or die "I couldn't get at log.txt";

		#open out file for downlink statistics
		open (DOWNLINK, ">".$outfilename) or die "$! error trying to overwrite";
	    # The original contents are gone, wave goodbye.

		$prev_time=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$rxBytes=0; #number of bytes received
		$delay=0;
		$num_pck=0;

		#downlink
		for $line (<LOGFILE>) {

			if($line =~ /^(.x)/) { #\s(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)/) {
		 		
				if($1 eq "Rx")
				{
					if($line =~ /(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)$/ )
					{
						if($1<=$prev_time) {
					 		$rxBytes+=$2;
					 		$delay+=$3;
					 		$num_pck+=1;
					 	}	
					 	else #update actual time, pkts, total delay and print throughput at that time
					 	{	
					 		if($num_pck > 0)
					 		{
						 		print DOWNLINK join("\t", ($prev_time, $rxBytes*8, $delay/$num_pck));
					 			print DOWNLINK "\n";
					 		}
					 		$rxBytes = $2;
					 		$delay = $3;	
					 		$num_pck=1;
					 		while($1 >= $prev_time)
					 		{
						 		$prev_time+=$sampling_time;
					 		}
						}
					}
				}
			}
			else
			{
				warn "Not usual pattern\n";
			}
		}

		close LOGFILE;
		close DOWNLINK;
	}


	## RLC UL throughput

	my @filelist = glob($outpath."mcUlRlcStats*");

	$basefilename = "throughputUl_RlcFilter.txt";
	#variables
	$sampling_time=0.05; #0.5s
	$app_start_time=0.5;

	#open out file
	open (MCSIMLIST, ">".$outpath."mcSimList_rlcUl.txt") or die "$! error trying to overwrite";
	# The original contents are gone, wave goodbye.

	for $path (@filelist) {
		print $path;
		print "\n";

		$file = basename($path);

		print $file;
		print "\n";

		my $version;
		my $date;
		if($file =~ /^mcUlRlcStats_(\w*)/)
		{
			$version = "mc";
			$date = $1;
			print MCSIMLIST $date."\n";
		}
		else
		{
			warn "Invalid\n";
		}
		$outfilename = $outpath.$version.$date.$basefilename;
		print $outfilename."\n";



		#open log file, update log file name when needed
		open (LOGFILE, $path) or die "I couldn't get at log.txt";

		#open out file for downlink statistics
		open (DOWNLINK, ">".$outfilename) or die "$! error trying to overwrite";
	    # The original contents are gone, wave goodbye.

		$prev_time=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$rxBytes=0; #number of bytes received
		$delay=0;
		$num_pck=0;

		#downlink
		for $line (<LOGFILE>) {

			if($line =~ /^(.x)/) { #\s(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)/) {
		 		
				if($1 eq "Rx")
				{
					if($line =~ /(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)$/ )
					{
						if($1<=$prev_time) {
					 		$rxBytes+=$2;
					 		$delay+=$3;
					 		$num_pck+=1;
					 	}	
					 	else #update actual time, pkts, total delay and print throughput at that time
					 	{	
					 		if($num_pck > 0)
					 		{
						 		print DOWNLINK join("\t", ($prev_time, $rxBytes*8, $delay/$num_pck));
					 			print DOWNLINK "\n";
					 		}
					 		$rxBytes = $2;
					 		$delay = $3;	
					 		$num_pck=1;
					 		while($1 >= $prev_time)
					 		{
						 		$prev_time+=$sampling_time;
					 		}
						}
					}
				}
			}
			else
			{
				warn "Not usual pattern\n";
			}
		}

		close LOGFILE;
		close DOWNLINK;
	}

	## X2 link throughput

	my @filelist = glob($outpath."mcX2Stats*");

	$basefilename = "x2throughput.txt";
	#variables
	$sampling_time=0.05; #0.5s
	$app_start_time=0.5;

	#open out file
	open (MCSIMLIST, ">".$outpath."mcSimList_x2.txt") or die "$! error trying to overwrite";
	# The original contents are gone, wave goodbye.

	for $path (@filelist) {
		print $path;
		print "\n";

		$file = basename($path);

		print $file;
		print "\n";

		my $version;
		my $date;
		if($file =~ /^mcX2Stats_(\w*)/)
		{
			$version = "mc";
			$date = $1;
			print MCSIMLIST $date."\n";
		}
		else
		{
			warn "Invalid\n";
		}
		$outfilename12 = $outpath.$version.$date."_12_".$basefilename;
		print $outfilename12."\n";
		$outfilename13 = $outpath.$version.$date."_13_".$basefilename;
		print $outfilename13."\n";
		$outfilename14 = $outpath.$version.$date."_14_".$basefilename;
		print $outfilename14."\n";
		$outfilename23 = $outpath.$version.$date."_23_".$basefilename;
		print $outfilename23."\n";
		$outfilename24 = $outpath.$version.$date."_24_".$basefilename;
		print $outfilename24."\n";
		$outfilename34 = $outpath.$version.$date."_34_".$basefilename;
		print $outfilename34."\n";

		#open log file, update log file name when needed
		open (LOGFILE, $path) or die "I couldn't get at log.txt";

		#open out file for downlink statistics
		open (DOWNLINK12, ">".$outfilename12) or die "$! error trying to overwrite";
		open (DOWNLINK13, ">".$outfilename13) or die "$! error trying to overwrite";
		open (DOWNLINK23, ">".$outfilename23) or die "$! error trying to overwrite";
		open (DOWNLINK14, ">".$outfilename14) or die "$! error trying to overwrite";
		open (DOWNLINK24, ">".$outfilename24) or die "$! error trying to overwrite";
		open (DOWNLINK34, ">".$outfilename34) or die "$! error trying to overwrite";

	    # The original contents are gone, wave goodbye.

		$prev_time12=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$prev_time13=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$prev_time23=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$prev_time14=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$prev_time24=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$prev_time34=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second

		$rxBytes12=0; #number of bytes received on link 12
		$rxBytes13=0; #number of bytes received on link 13
		$rxBytes23=0; #number of bytes received on link 23
		$rxBytes14=0; #number of bytes received on link 14
		$rxBytes24=0; #number of bytes received on link 24
		$rxBytes34=0; #number of bytes received on link 34


		$delay12=0;
		$num_pck12=0;
		$delay13=0;
		$num_pck13=0;
		$delay23=0;
		$num_pck23=0;
		$delay14=0;
		$num_pck14=0;
		$delay24=0;
		$num_pck24=0;
		$delay34=0;
		$num_pck34=0;

		$num_data12=0;
		$num_data13=0;
		$num_data23=0;
		$num_data14=0;
		$num_data24=0;
		$num_data34=0;

		for $line (<LOGFILE>) {

			if($line =~ /(\d+\.*\d*)\s(\d+)\s(\d+)\s(\d+)\s(\d+)\s(\d+)$/ )
			{
				if(($2==1 && $3==2) || ($2==2 && $3==1)) {
					if($1<=$prev_time12) {
				 		$rxBytes12+=$4;
				 		$delay12+=$5;
				 		$num_pck12+=1;
				 		if($6==1)
				 		{
				 			$num_data12+=1;
				 		}
				 	}
				 	else #update actual time, pkts, total delay and print throughput at that time
				 	{	
				 		if($num_pck12 > 0)
				 		{
				 			print DOWNLINK12 join("\t", ($prev_time12, $rxBytes12*8, $delay12/$num_pck12, $num_pck12, $num_data12));
				 			print DOWNLINK12 "\n";
				 		}
				 		$rxBytes12 = $4;
				 		$delay12 = $5;	
				 		$num_pck12=1;
				 		while($1 >= $prev_time12)
				 		{
					 		$prev_time12+=$sampling_time;
				 		}
				 		if($6==1)
				 		{
				 			$num_data12=1;
				 		}
				 		else
				 		{
				 			$num_data12=0;
				 		}
					}
				}

				if(($2==1 && $3==3) || ($2==3 && $3==1)) {
					if($1<=$prev_time13) {
				 		$rxBytes13+=$4;
				 		$delay13+=$5;
				 		$num_pck13+=1;
				 		if($6==1)
				 		{
				 			$num_data13+=1;
				 		}
				 	}
				 	else #update actual time, pkts, total delay and print throughput at that time
				 	{	
				 		if($num_pck13 > 0)
				 		{
					 		print DOWNLINK13 join("\t", ($prev_time13, $rxBytes13*8, $delay13/$num_pck13, $num_pck13, $num_data13));
				 			print DOWNLINK13 "\n";
				 		}
				 		$rxBytes13 = $4;
				 		$delay13 = $5;	
				 		$num_pck13=1;
				 		while($1 >= $prev_time13)
				 		{
					 		$prev_time13+=$sampling_time;
				 		}
				 		if($6==1)
				 		{
				 			$num_data13=1;
				 		}
				 		else
				 		{
				 			$num_data13=0;
				 		}
					}
				}

				if(($2==3 && $3==2) || ($2==2 && $3==3)) {
					if($1<=$prev_time23) {
				 		$rxBytes23+=$4;
				 		$delay23+=$5;
				 		$num_pck23+=1;
				 		if($6==1)
				 		{
				 			$num_data23+=1;
				 		}
				 	}
				 	else #update actual time, pkts, total delay and print throughput at that time
				 	{	
				 		if($num_pck23 > 0)
				 		{
				 			print DOWNLINK23 join("\t", ($prev_time23, $rxBytes23*8, $delay23/$num_pck23, $num_pck23, $num_data23));
				 			print DOWNLINK23 "\n";
				 		}
				 		$rxBytes23 = $4;
				 		$delay23 = $5;	
				 		$num_pck23=1;
						while($1 >= $prev_time23)
				 		{
					 		$prev_time23+=$sampling_time;
				 		}			 		
				 		if($6==1)
				 		{
				 			$num_data23=1;
				 		}
				 		else
				 		{
				 			$num_data23=0;
				 		}
					}
				}

				if(($2==1 && $3==4) || ($2==4 && $3==1)) {
					if($1<=$prev_time14) {
				 		$rxBytes14+=$4;
				 		$delay14+=$5;
				 		$num_pck14+=1;
				 		if($6==1)
				 		{
				 			$num_data14+=1;
				 		}
				 	}
				 	else #update actual time, pkts, total delay and print throughput at that time
				 	{	
				 		if($num_pck14 > 0)
				 		{
				 			print DOWNLINK14 join("\t", ($prev_time14, $rxBytes14*8, $delay14/$num_pck14, $num_pck14, $num_data14));
				 			print DOWNLINK14 "\n";
				 		}
				 		$rxBytes14 = $4;
				 		$delay14 = $5;	
				 		$num_pck14=1;
						while($1 >= $prev_time14)
				 		{
					 		$prev_time14+=$sampling_time;
				 		}			 		
				 		if($6==1)
				 		{
				 			$num_data14=1;
				 		}
				 		else
				 		{
				 			$num_data14=0;
				 		}
					}
				}

				if(($2==2 && $3==4) || ($2==4 && $3==2)) {
					if($1<=$prev_time24) {
				 		$rxBytes24+=$4;
				 		$delay24+=$5;
				 		$num_pck24+=1;
				 		if($6==1)
				 		{
				 			$num_data24+=1;
				 		}
				 	}
				 	else #update actual time, pkts, total delay and print throughput at that time
				 	{	
				 		if($num_pck24 > 0)
				 		{
				 			print DOWNLINK24 join("\t", ($prev_time24, $rxBytes24*8, $delay24/$num_pck24, $num_pck24, $num_data24));
				 			print DOWNLINK24 "\n";
				 		}
				 		$rxBytes24 = $4;
				 		$delay24 = $5;	
				 		$num_pck24=1;
						while($1 >= $prev_time24)
				 		{
					 		$prev_time24+=$sampling_time;
				 		}			 		
				 		if($6==1)
				 		{
				 			$num_data24=1;
				 		}
				 		else
				 		{
				 			$num_data24=0;
				 		}
					}
				}

				if(($2==3 && $3==4) || ($2==4 && $3==3)) {
					if($1<=$prev_time34) {
				 		$rxBytes34+=$4;
				 		$delay34+=$5;
				 		$num_pck34+=1;
				 		if($6==1)
				 		{
				 			$num_data34+=1;
				 		}
				 	}
				 	else #update actual time, pkts, total delay and print throughput at that time
				 	{	
				 		if($num_pck34 > 0)
				 		{
				 			print DOWNLINK34 join("\t", ($prev_time34, $rxBytes34*8, $delay34/$num_pck34, $num_pck34, $num_data34));
				 			print DOWNLINK34 "\n";
				 		}
				 		$rxBytes34 = $4;
				 		$delay34 = $5;	
				 		$num_pck34=1;
						while($1 >= $prev_time34)
				 		{
					 		$prev_time34+=$sampling_time;
				 		}			 		
				 		if($6==1)
				 		{
				 			$num_data34=1;
				 		}
				 		else
				 		{
				 			$num_data34=0;
				 		}
					}
				}
			 		
			}
			else
			{
				warn "Not usual pattern\n";
			}
		}

		close LOGFILE;
		close DOWNLINK12;
		close DOWNLINK13;
		close DOWNLINK23;
		close DOWNLINK24;
		close DOWNLINK34;
		close DOWNLINK14;

	}

	## RLC RRC DL throughput (only srb0 and srb1 on lc0 and lc1)
	 
	my @filelist = glob($outpath."mcDlRlcStats*");

	$basefilename = "rrcDl_RlcFilter.txt";
	#variables
	$sampling_time=0.05; #0.5s
	$app_start_time=0.5;

	#open out file
	open (MCSIMLIST, ">".$outpath."mcSimList_rlcDl.txt") or die "$! error trying to overwrite";
	# The original contents are gone, wave goodbye.

	for $path (@filelist) {
		print $path;
		print "\n";

		$file = basename($path);

		print $file;
		print "\n";

		my $version;
		my $date;
		if($file =~ /^mcDlRlcStats_(\w*)/)
		{
			$version = "mc";
			$date = $1;
			print MCSIMLIST $date."\n";
		}
		else
		{
			warn "Invalid\n";
		}
		$outfilename = $outpath.$version.$date.$basefilename;
		print $outfilename."\n";



		#open log file, update log file name when needed
		open (LOGFILE, $path) or die "I couldn't get at log.txt";

		#open out file for downlink statistics
		open (DOWNLINK, ">".$outfilename) or die "$! error trying to overwrite";
	    # The original contents are gone, wave goodbye.

		$prev_time=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$rxBytes=0; #number of bytes received
		$delay=0;
		$num_pck=0;

		#downlink
		for $line (<LOGFILE>) {

			if($line =~ /^(.x)/) { #\s(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)/) {
		 		
				if($1 eq "Rx")
				{
					if($line =~ /(\d+\.*\d*)\s\d+\s\d+\s(\d+)\s(\d+)\s(\d+)$/ )
					{
						if($2==0 || $2==1)
						{
							if($1<=$prev_time) {
						 		$rxBytes+=$3;
						 		$delay+=$4;
						 		$num_pck+=1;
						 	}	
						 	else #update actual time, pkts, total delay and print throughput at that time
						 	{	
						 		if($num_pck > 0)
						 		{
							 		print DOWNLINK join("\t", ($prev_time, $rxBytes*8, $delay/$num_pck));
						 			print DOWNLINK "\n";
						 		}
						 		$rxBytes = $3;
						 		$delay = $4;	
						 		$num_pck=1;
						 		while($1 >= $prev_time)
						 		{
							 		$prev_time+=$sampling_time;
						 		}
							}	
						}
					}
				}
			}
			else
			{
				warn "Not usual pattern\n";
			}
		}

		close LOGFILE;
		close DOWNLINK;
	}


	## RLC RRC UL throughput (only srb0 and srb1 on lc0 and lc1)
	 
	my @filelist = glob($outpath."mcUlRlcStats*");

	$basefilename = "rrcUl_RlcFilter.txt";
	#variables
	$sampling_time=0.05; #0.5s
	$app_start_time=0.5;

	#open out file
	open (MCSIMLIST, ">".$outpath."mcSimList_rlcUl.txt") or die "$! error trying to overwrite";
	# The original contents are gone, wave goodbye.

	for $path (@filelist) {
		print $path;
		print "\n";

		$file = basename($path);

		print $file;
		print "\n";

		my $version;
		my $date;
		if($file =~ /^mcUlRlcStats_(\w*)/)
		{
			$version = "mc";
			$date = $1;
			print MCSIMLIST $date."\n";
		}
		else
		{
			warn "Invalid\n";
		}
		$outfilename = $outpath.$version.$date.$basefilename;
		print $outfilename."\n";



		#open log file, update log file name when needed
		open (LOGFILE, $path) or die "I couldn't get at log.txt";

		#open out file for downlink statistics
		open (DOWNLINK, ">".$outfilename) or die "$! error trying to overwrite";
	    # The original contents are gone, wave goodbye.

		$prev_time=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$rxBytes=0; #number of bytes received
		$delay=0;
		$num_pck=0;

		#downlink
		for $line (<LOGFILE>) {

			if($line =~ /^(.x)/) { #\s(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)/) {
		 		
				if($1 eq "Rx")
				{
					if($line =~ /(\d+\.*\d*)\s\d+\s\d+\s(\d+)\s(\d+)\s(\d+)$/ )
					{
						if($2==0 || $2==1)
						{
							if($1<=$prev_time) {
						 		$rxBytes+=$3;
						 		$delay+=$4;
						 		$num_pck+=1;
						 	}	
						 	else #update actual time, pkts, total delay and print throughput at that time
						 	{	
						 		if($num_pck > 0)
						 		{
							 		print DOWNLINK join("\t", ($prev_time, $rxBytes*8, $delay/$num_pck));
						 			print DOWNLINK "\n";
						 		}
						 		$rxBytes = $3;
						 		$delay = $4;	
						 		$num_pck=1;
						 		while($1 >= $prev_time)
						 		{
							 		$prev_time+=$sampling_time;
						 		}
							}	
						}
					}
				}
			}
			else
			{
				warn "Not usual pattern\n";
			}
		}

		close LOGFILE;
		close DOWNLINK;
	}

}
else
{
	# get a list of files matching DlPdcpStats
	my @filelist = glob($outpath."hhDlPdcpStats*");

	print $outpath."\n";

	$basefilename = "throughputDl_PdcpFilter.txt";
	#variables
	$sampling_time=0.05; #0.5s
	$app_start_time=0.5;

	#open out file
	open (HHSIMLIST, ">".$outpath."hhSimList.txt") or die "$! error trying to overwrite";
	# The original contents are gone, wave goodbye.

	for $path (@filelist) {
		print $path;
		print "\n";

		$file = basename($path);

		print $file;
		print "\n";

		my $version;
		my $date;
		if($file =~ /^hhDlPdcpStats_(\w*)/)
		{
			$version = "hh";
			$date = $1;
			print HHSIMLIST $date."\n";
		}
		else
		{
			warn "Invalid\n";
		}
		$outfilename = $outpath.$version.$date.$basefilename;
		print $outfilename."\n";

		#open log file, update log file name when needed
		open (LOGFILE, $path) or die "I couldn't get at log.txt";

		#open out file for downlink statistics
		open (DOWNLINK, ">".$outfilename) or die "$! error trying to overwrite";
	    # The original contents are gone, wave goodbye.

		$prev_time=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$rxBytes=0; #number of bytes received
		$delay=0;
		$num_pck=0;

		#downlink
		for $line (<LOGFILE>) {

			if($line =~ /^(.x)/) { #\s(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)/) {
		 		
				if($1 eq "Rx")
				{
					if($line =~ /(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)$/ )
					{
						if($1<=$prev_time) {
					 		$rxBytes+=$2;
					 		$delay+=$3;
					 		$num_pck+=1;
					 	}	
					 	else #update actual time, pkts, total delay and print throughput at that time
					 	{	
					 		if($num_pck > 0)
					 		{
						 		print DOWNLINK join("\t", ($prev_time, $rxBytes*8, $delay/$num_pck));
					 			print DOWNLINK "\n";
					 		}
					 		$rxBytes = $2;
					 		$delay = $3;	
					 		$num_pck=1;
					 		while($1 >= $prev_time)
					 		{
						 		$prev_time+=$sampling_time;
					 		}
						}
					}
				}
			}
			else
			{
				warn "Not usual pattern\n";
			}
		}

		close LOGFILE;
		close DOWNLINK;
	}

	## Uplink throughput

	# get a list of files matching DlPdcpStats
	my @filelist = glob($outpath."hhUlPdcpStats*");

	$basefilename = "throughputUl_PdcpFilter.txt";
	#variables
	$sampling_time=0.05; #0.5s
	$app_start_time=0.5;

	#open out file
	open (MCSIMLIST, ">".$outpath."hhSimList_up.txt") or die "$! error trying to overwrite";
	# The original contents are gone, wave goodbye.

	for $path (@filelist) {
		print $path;
		print "\n";

		$file = basename($path);

		print $file;
		print "\n";

		my $version;
		my $date;
		if($file =~ /^hhUlPdcpStats_(\w*)/)
		{
			$version = "hh";
			$date = $1;
			print MCSIMLIST $date."\n";
		}
		else
		{
			warn "Invalid\n";
		}
		$outfilename = $outpath.$version.$date.$basefilename;
		print $outfilename."\n";



		#open log file, update log file name when needed
		open (LOGFILE, $path) or die "I couldn't get at log.txt";

		#open out file for downlink statistics
		open (DOWNLINK, ">".$outfilename) or die "$! error trying to overwrite";
	    # The original contents are gone, wave goodbye.

		$prev_time=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$rxBytes=0; #number of bytes received
		$delay=0;
		$num_pck=0;

		#downlink
		for $line (<LOGFILE>) {

			if($line =~ /^(.x)/) { #\s(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)/) {
		 		
				if($1 eq "Rx")
				{
					if($line =~ /(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)$/ )
					{
						if($1<=$prev_time) {
					 		$rxBytes+=$2;
					 		$delay+=$3;
					 		$num_pck+=1;
					 	}	
					 	else #update actual time, pkts, total delay and print throughput at that time
					 	{	
					 		if($num_pck > 0)
					 		{
						 		print DOWNLINK join("\t", ($prev_time, $rxBytes*8, $delay/$num_pck));
					 			print DOWNLINK "\n";
					 		}
					 		$rxBytes = $2;
					 		$delay = $3;	
					 		$num_pck=1;
					 		while($1 >= $prev_time)
					 		{
						 		$prev_time+=$sampling_time;
					 		}
						}
					}
				}
			}
			else
			{
				warn "Not usual pattern\n";
			}
		}

		close LOGFILE;
		close DOWNLINK;
	}

	## RLC throughput

	my @filelist = glob($outpath."hhDlRlcStats*");

	$basefilename = "throughputDl_RlcFilter.txt";
	#variables
	$sampling_time=0.05; #0.5s
	$app_start_time=0.5;

	#open out file
	open (MCSIMLIST, ">".$outpath."hhSimList_rlcDl.txt") or die "$! error trying to overwrite";
	# The original contents are gone, wave goodbye.

	for $path (@filelist) {
		print $path;
		print "\n";

		$file = basename($path);

		print $file;
		print "\n";

		my $version;
		my $date;
		if($file =~ /^hhDlRlcStats_(\w*)/)
		{
			$version = "hh";
			$date = $1;
			print MCSIMLIST $date."\n";
		}
		else
		{
			warn "Invalid\n";
		}
		$outfilename = $outpath.$version.$date.$basefilename;
		print $outfilename."\n";



		#open log file, update log file name when needed
		open (LOGFILE, $path) or die "I couldn't get at log.txt";

		#open out file for downlink statistics
		open (DOWNLINK, ">".$outfilename) or die "$! error trying to overwrite";
	    # The original contents are gone, wave goodbye.

		$prev_time=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$rxBytes=0; #number of bytes received
		$delay=0;
		$num_pck=0;

		#downlink
		for $line (<LOGFILE>) {

			if($line =~ /^(.x)/) { #\s(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)/) {
		 		
				if($1 eq "Rx")
				{
					if($line =~ /(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)$/ )
					{
						if($1<=$prev_time) {
					 		$rxBytes+=$2;
					 		$delay+=$3;
					 		$num_pck+=1;
					 	}	
					 	else #update actual time, pkts, total delay and print throughput at that time
					 	{	
					 		if($num_pck > 0)
					 		{
						 		print DOWNLINK join("\t", ($prev_time, $rxBytes*8, $delay/$num_pck));
					 			print DOWNLINK "\n";
					 		}
					 		$rxBytes = $2;
					 		$delay = $3;	
					 		$num_pck=1;
					 		while($1 >= $prev_time)
					 		{
						 		$prev_time+=$sampling_time;
					 		}
						}
					}
				}
			}
			else
			{
				warn "Not usual pattern\n";
			}
		}

		close LOGFILE;
		close DOWNLINK;
	}


	## RLC UL throughput

	my @filelist = glob($outpath."hhUlRlcStats*");

	$basefilename = "throughputUl_RlcFilter.txt";
	#variables
	$sampling_time=0.05; #0.5s
	$app_start_time=0.5;

	#open out file
	open (MCSIMLIST, ">".$outpath."hhSimList_rlcUl.txt") or die "$! error trying to overwrite";
	# The original contents are gone, wave goodbye.

	for $path (@filelist) {
		print $path;
		print "\n";

		$file = basename($path);

		print $file;
		print "\n";

		my $version;
		my $date;
		if($file =~ /^hhUlRlcStats_(\w*)/)
		{
			$version = "hh";
			$date = $1;
			print MCSIMLIST $date."\n";
		}
		else
		{
			warn "Invalid\n";
		}
		$outfilename = $outpath.$version.$date.$basefilename;
		print $outfilename."\n";



		#open log file, update log file name when needed
		open (LOGFILE, $path) or die "I couldn't get at log.txt";

		#open out file for downlink statistics
		open (DOWNLINK, ">".$outfilename) or die "$! error trying to overwrite";
	    # The original contents are gone, wave goodbye.

		$prev_time=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$rxBytes=0; #number of bytes received
		$delay=0;
		$num_pck=0;

		#downlink
		for $line (<LOGFILE>) {

			if($line =~ /^(.x)/) { #\s(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)/) {
		 		
				if($1 eq "Rx")
				{
					if($line =~ /(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)$/ )
					{
						if($1<=$prev_time) {
					 		$rxBytes+=$2;
					 		$delay+=$3;
					 		$num_pck+=1;
					 	}	
					 	else #update actual time, pkts, total delay and print throughput at that time
					 	{	
					 		if($num_pck > 0)
					 		{
						 		print DOWNLINK join("\t", ($prev_time, $rxBytes*8, $delay/$num_pck));
					 			print DOWNLINK "\n";
					 		}
					 		$rxBytes = $2;
					 		$delay = $3;	
					 		$num_pck=1;
					 		while($1 >= $prev_time)
					 		{
						 		$prev_time+=$sampling_time;
					 		}
						}
					}
				}
			}
			else
			{
				warn "Not usual pattern\n";
			}
		}

		close LOGFILE;
		close DOWNLINK;
	}

	## X2 link throughput

	my @filelist = glob($outpath."hhX2Stats*");

	$basefilename = "x2throughput.txt";
	#variables
	$sampling_time=0.05; #0.5s
	$app_start_time=0.5;

	#open out file
	open (MCSIMLIST, ">".$outpath."hhSimList_x2.txt") or die "$! error trying to overwrite";
	# The original contents are gone, wave goodbye.

	for $path (@filelist) {
		print $path;
		print "\n";

		$file = basename($path);

		print $file;
		print "\n";

		my $version;
		my $date;
		if($file =~ /^hhX2Stats_(\w*)/)
		{
			$version = "hh";
			$date = $1;
			print MCSIMLIST $date."\n";
		}
		else
		{
			warn "Invalid\n";
		}
		$outfilename12 = $outpath.$version.$date."_12_".$basefilename;
		print $outfilename12."\n";
		$outfilename13 = $outpath.$version.$date."_13_".$basefilename;
		print $outfilename13."\n";
		$outfilename14 = $outpath.$version.$date."_14_".$basefilename;
		print $outfilename14."\n";
		$outfilename23 = $outpath.$version.$date."_23_".$basefilename;
		print $outfilename23."\n";
		$outfilename24 = $outpath.$version.$date."_24_".$basefilename;
		print $outfilename24."\n";
		$outfilename34 = $outpath.$version.$date."_34_".$basefilename;
		print $outfilename34."\n";

		#open log file, update log file name when needed
		open (LOGFILE, $path) or die "I couldn't get at log.txt";

		#open out file for downlink statistics
		open (DOWNLINK12, ">".$outfilename12) or die "$! error trying to overwrite";
		open (DOWNLINK13, ">".$outfilename13) or die "$! error trying to overwrite";
		open (DOWNLINK23, ">".$outfilename23) or die "$! error trying to overwrite";
		open (DOWNLINK14, ">".$outfilename14) or die "$! error trying to overwrite";
		open (DOWNLINK24, ">".$outfilename24) or die "$! error trying to overwrite";
		open (DOWNLINK34, ">".$outfilename34) or die "$! error trying to overwrite";

	    # The original contents are gone, wave goodbye.

		$prev_time12=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$prev_time13=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$prev_time23=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$prev_time14=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$prev_time24=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$prev_time34=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second

		$rxBytes12=0; #number of bytes received on link 12
		$rxBytes13=0; #number of bytes received on link 13
		$rxBytes23=0; #number of bytes received on link 23
		$rxBytes14=0; #number of bytes received on link 14
		$rxBytes24=0; #number of bytes received on link 24
		$rxBytes34=0; #number of bytes received on link 34


		$delay12=0;
		$num_pck12=0;
		$delay13=0;
		$num_pck13=0;
		$delay23=0;
		$num_pck23=0;
		$delay14=0;
		$num_pck14=0;
		$delay24=0;
		$num_pck24=0;
		$delay34=0;
		$num_pck34=0;

		$num_data12=0;
		$num_data13=0;
		$num_data23=0;
		$num_data14=0;
		$num_data24=0;
		$num_data34=0;

		for $line (<LOGFILE>) {

			if($line =~ /(\d+\.*\d*)\s(\d+)\s(\d+)\s(\d+)\s(\d+)\s(\d+)$/ )
			{
				if(($2==1 && $3==2) || ($2==2 && $3==1)) {
					if($1<=$prev_time12) {
				 		$rxBytes12+=$4;
				 		$delay12+=$5;
				 		$num_pck12+=1;
				 		if($6==1)
				 		{
				 			$num_data12+=1;
				 		}
				 	}
				 	else #update actual time, pkts, total delay and print throughput at that time
				 	{	
				 		if($num_pck12 > 0)
				 		{
				 			print DOWNLINK12 join("\t", ($prev_time12, $rxBytes12*8, $delay12/$num_pck12, $num_pck12, $num_data12));
				 			print DOWNLINK12 "\n";
				 		}
				 		$rxBytes12 = $4;
				 		$delay12 = $5;	
				 		$num_pck12=1;
				 		while($1 >= $prev_time12)
				 		{
					 		$prev_time12+=$sampling_time;
				 		}
				 		if($6==1)
				 		{
				 			$num_data12=1;
				 		}
				 		else
				 		{
				 			$num_data12=0;
				 		}
					}
				}

				if(($2==1 && $3==3) || ($2==3 && $3==1)) {
					if($1<=$prev_time13) {
				 		$rxBytes13+=$4;
				 		$delay13+=$5;
				 		$num_pck13+=1;
				 		if($6==1)
				 		{
				 			$num_data13+=1;
				 		}
				 	}
				 	else #update actual time, pkts, total delay and print throughput at that time
				 	{	
				 		if($num_pck13 > 0)
				 		{
					 		print DOWNLINK13 join("\t", ($prev_time13, $rxBytes13*8, $delay13/$num_pck13, $num_pck13, $num_data13));
				 			print DOWNLINK13 "\n";
				 		}
				 		$rxBytes13 = $4;
				 		$delay13 = $5;	
				 		$num_pck13=1;
				 		while($1 >= $prev_time13)
				 		{
					 		$prev_time13+=$sampling_time;
				 		}
				 		if($6==1)
				 		{
				 			$num_data13=1;
				 		}
				 		else
				 		{
				 			$num_data13=0;
				 		}
					}
				}

				if(($2==3 && $3==2) || ($2==2 && $3==3)) {
					if($1<=$prev_time23) {
				 		$rxBytes23+=$4;
				 		$delay23+=$5;
				 		$num_pck23+=1;
				 		if($6==1)
				 		{
				 			$num_data23+=1;
				 		}
				 	}
				 	else #update actual time, pkts, total delay and print throughput at that time
				 	{	
				 		if($num_pck23 > 0)
				 		{
				 			print DOWNLINK23 join("\t", ($prev_time23, $rxBytes23*8, $delay23/$num_pck23, $num_pck23, $num_data23));
				 			print DOWNLINK23 "\n";
				 		}
				 		$rxBytes23 = $4;
				 		$delay23 = $5;	
				 		$num_pck23=1;
						while($1 >= $prev_time23)
				 		{
					 		$prev_time23+=$sampling_time;
				 		}			 		
				 		if($6==1)
				 		{
				 			$num_data23=1;
				 		}
				 		else
				 		{
				 			$num_data23=0;
				 		}
					}
				}

				if(($2==1 && $3==4) || ($2==4 && $3==1)) {
					if($1<=$prev_time14) {
				 		$rxBytes14+=$4;
				 		$delay14+=$5;
				 		$num_pck14+=1;
				 		if($6==1)
				 		{
				 			$num_data14+=1;
				 		}
				 	}
				 	else #update actual time, pkts, total delay and print throughput at that time
				 	{	
				 		if($num_pck14 > 0)
				 		{
				 			print DOWNLINK14 join("\t", ($prev_time14, $rxBytes14*8, $delay14/$num_pck14, $num_pck14, $num_data14));
				 			print DOWNLINK14 "\n";
				 		}
				 		$rxBytes14 = $4;
				 		$delay14 = $5;	
				 		$num_pck14=1;
						while($1 >= $prev_time14)
				 		{
					 		$prev_time14+=$sampling_time;
				 		}			 		
				 		if($6==1)
				 		{
				 			$num_data14=1;
				 		}
				 		else
				 		{
				 			$num_data14=0;
				 		}
					}
				}

				if(($2==2 && $3==4) || ($2==4 && $3==2)) {
					if($1<=$prev_time24) {
				 		$rxBytes24+=$4;
				 		$delay24+=$5;
				 		$num_pck24+=1;
				 		if($6==1)
				 		{
				 			$num_data24+=1;
				 		}
				 	}
				 	else #update actual time, pkts, total delay and print throughput at that time
				 	{	
				 		if($num_pck24 > 0)
				 		{
				 			print DOWNLINK24 join("\t", ($prev_time24, $rxBytes24*8, $delay24/$num_pck24, $num_pck24, $num_data24));
				 			print DOWNLINK24 "\n";
				 		}
				 		$rxBytes24 = $4;
				 		$delay24 = $5;	
				 		$num_pck24=1;
						while($1 >= $prev_time24)
				 		{
					 		$prev_time24+=$sampling_time;
				 		}			 		
				 		if($6==1)
				 		{
				 			$num_data24=1;
				 		}
				 		else
				 		{
				 			$num_data24=0;
				 		}
					}
				}

				if(($2==3 && $3==4) || ($2==4 && $3==3)) {
					if($1<=$prev_time34) {
				 		$rxBytes34+=$4;
				 		$delay34+=$5;
				 		$num_pck34+=1;
				 		if($6==1)
				 		{
				 			$num_data34+=1;
				 		}
				 	}
				 	else #update actual time, pkts, total delay and print throughput at that time
				 	{	
				 		if($num_pck34 > 0)
				 		{
				 			print DOWNLINK34 join("\t", ($prev_time34, $rxBytes34*8, $delay34/$num_pck34, $num_pck34, $num_data34));
				 			print DOWNLINK34 "\n";
				 		}
				 		$rxBytes34 = $4;
				 		$delay34 = $5;	
				 		$num_pck34=1;
						while($1 >= $prev_time34)
				 		{
					 		$prev_time34+=$sampling_time;
				 		}			 		
				 		if($6==1)
				 		{
				 			$num_data34=1;
				 		}
				 		else
				 		{
				 			$num_data34=0;
				 		}
					}
				}
			 		
			}
			else
			{
				warn "Not usual pattern\n";
			}
		}

		close LOGFILE;
		close DOWNLINK12;
		close DOWNLINK13;
		close DOWNLINK23;
		close DOWNLINK24;
		close DOWNLINK34;
		close DOWNLINK14;

	}

	## RLC RRC DL throughput (only srb0 and srb1 on lc0 and lc1)
	 
	my @filelist = glob($outpath."hhDlRlcStats*");

	$basefilename = "rrcDl_RlcFilter.txt";
	#variables
	$sampling_time=0.05; #0.5s
	$app_start_time=0.5;

	#open out file
	open (MCSIMLIST, ">".$outpath."hhSimList_rlcDl.txt") or die "$! error trying to overwrite";
	# The original contents are gone, wave goodbye.

	for $path (@filelist) {
		print $path;
		print "\n";

		$file = basename($path);

		print $file;
		print "\n";

		my $version;
		my $date;
		if($file =~ /^hhDlRlcStats_(\w*)/)
		{
			$version = "hh";
			$date = $1;
			print MCSIMLIST $date."\n";
		}
		else
		{
			warn "Invalid\n";
		}
		$outfilename = $outpath.$version.$date.$basefilename;
		print $outfilename."\n";



		#open log file, update log file name when needed
		open (LOGFILE, $path) or die "I couldn't get at log.txt";

		#open out file for downlink statistics
		open (DOWNLINK, ">".$outfilename) or die "$! error trying to overwrite";
	    # The original contents are gone, wave goodbye.

		$prev_time=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$rxBytes=0; #number of bytes received
		$delay=0;
		$num_pck=0;

		#downlink
		for $line (<LOGFILE>) {

			if($line =~ /^(.x)/) { #\s(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)/) {
		 		
				if($1 eq "Rx")
				{
					if($line =~ /(\d+\.*\d*)\s\d+\s\d+\s(\d+)\s(\d+)\s(\d+)$/ )
					{
						if($2==0 || $2==1)
						{
							if($1<=$prev_time) {
						 		$rxBytes+=$3;
						 		$delay+=$4;
						 		$num_pck+=1;
						 	}	
						 	else #update actual time, pkts, total delay and print throughput at that time
						 	{	
						 		if($num_pck > 0)
						 		{
							 		print DOWNLINK join("\t", ($prev_time, $rxBytes*8, $delay/$num_pck));
						 			print DOWNLINK "\n";
						 		}
						 		$rxBytes = $3;
						 		$delay = $4;	
						 		$num_pck=1;
						 		while($1 >= $prev_time)
						 		{
							 		$prev_time+=$sampling_time;
						 		}
							}	
						}
					}
				}
			}
			else
			{
				warn "Not usual pattern\n";
			}
		}

		close LOGFILE;
		close DOWNLINK;
	}


	## RLC RRC UL throughput (only srb0 and srb1 on lc0 and lc1)
	 
	my @filelist = glob($outpath."hhUlRlcStats*");

	$basefilename = "rrcUl_RlcFilter.txt";
	#variables
	$sampling_time=0.05; #0.5s
	$app_start_time=0.5;

	#open out file
	open (MCSIMLIST, ">".$outpath."hhSimList_rlcUl.txt") or die "$! error trying to overwrite";
	# The original contents are gone, wave goodbye.

	for $path (@filelist) {
		print $path;
		print "\n";

		$file = basename($path);

		print $file;
		print "\n";

		my $version;
		my $date;
		if($file =~ /^hhUlRlcStats_(\w*)/)
		{
			$version = "hh";
			$date = $1;
			print MCSIMLIST $date."\n";
		}
		else
		{
			warn "Invalid\n";
		}
		$outfilename = $outpath.$version.$date.$basefilename;
		print $outfilename."\n";



		#open log file, update log file name when needed
		open (LOGFILE, $path) or die "I couldn't get at log.txt";

		#open out file for downlink statistics
		open (DOWNLINK, ">".$outfilename) or die "$! error trying to overwrite";
	    # The original contents are gone, wave goodbye.

		$prev_time=$app_start_time+$sampling_time; #$sampling_time; #it will be updated every sampling_time second
		$rxBytes=0; #number of bytes received
		$delay=0;
		$num_pck=0;

		#downlink
		for $line (<LOGFILE>) {

			if($line =~ /^(.x)/) { #\s(\d+\.*\d*)\s\d+\s\d+\s\d+\s(\d+)\s(\d+)/) {
		 		
				if($1 eq "Rx")
				{
					if($line =~ /(\d+\.*\d*)\s\d+\s\d+\s(\d+)\s(\d+)\s(\d+)$/ )
					{
						if($2==0 || $2==1)
						{
							if($1<=$prev_time) {
						 		$rxBytes+=$3;
						 		$delay+=$4;
						 		$num_pck+=1;
						 	}	
						 	else #update actual time, pkts, total delay and print throughput at that time
						 	{	
						 		if($num_pck > 0)
						 		{
							 		print DOWNLINK join("\t", ($prev_time, $rxBytes*8, $delay/$num_pck));
						 			print DOWNLINK "\n";
						 		}
						 		$rxBytes = $3;
						 		$delay = $4;	
						 		$num_pck=1;
						 		while($1 >= $prev_time)
						 		{
							 		$prev_time+=$sampling_time;
						 		}
							}	
						}
					}
				}
			}
			else
			{
				warn "Not usual pattern\n";
			}
		}

		close LOGFILE;
		close DOWNLINK;
	}

}



