# This script is used to read and sample the simulation traces
# Usage: perl read_traces.pl -[argument] [value]
# To show the list of the possible arguments use -h
# Each sampled trace is saved in a separate file [trace name]_sampled.txt

use strict;
use warnings;
use diagnostics;

use feature 'say';

use feature "switch";

use Data::Dumper qw(Dumper); # to parse arguments from the CommandLine

# use Statistics::Descriptive; # to compute mean and variance
                             # http://search.cpan.org/~shlomif/Statistics-Descriptive-3.0612/lib/Statistics/Descriptive.pm

# use Scalar::Util qw(looks_like_number); # this is useful to check wheater a
                                          # string can be converted into a
                                          # number


my @sampleTrace = (0, # if sampleTrace[0] the script samples PacketSinkDlRx.txt
                   0, # if sampleTrace[1] the script samples PacketSinkUlRx.txt
                   0, # if sampleTrace[2] the script samples DlPdcpStats.txt
                   0, # if sampleTrace[3] the script samples UlPdcpStats.txt
                   0, # if sampleTrace[4] the script samples DlTxMac.txt
                   0, # if sampleTrace[5] the script samples UlTxMac.txt
                   0, # if sampleTrace[6] the script samples DlRlcStats.txt
                   0); # if sampleTrace[7] the script samples UlRlcStats.txt


my $inputFilePath = "";
my $saveSampledTrace = 1;
my $samplingTime = 0.005; # sampling time
my $numOfActiveCc = 1; # number of active CCs

# read the arguments
for(my $i=0; $i<scalar(@ARGV); $i++)
{
  my $arg = $ARGV[$i];

  if ($arg eq "-PacketSinkDlRx")
  {
    $sampleTrace[0] = 1;
  }
  elsif ($arg eq "-PacketSinkUlRx")
  {
    $sampleTrace[1] = 1;
  }
  elsif ($arg eq "-DlPdcpStats")
  {
    $sampleTrace[2] = 1;
  }
  elsif ($arg eq "-UlPdcpStats")
  {
    $sampleTrace[3] = 1;
  }
  elsif ($arg eq "-DlTxMac")
  {
    $sampleTrace[4] = 1;
  }
  elsif ($arg eq "-UlTxMac")
  {
    $sampleTrace[5] = 1;
  }
  elsif ($arg eq "-DlRlcStats")
  {
    $sampleTrace[6] = 1;
  }
  elsif ($arg eq "-UlRlcStats")
  {
    $sampleTrace[7] = 1;
  }
  elsif ($arg eq "-numOfCc")
  {
    $numOfActiveCc = $ARGV[++$i];
  }
  elsif ($arg eq "-samplingTime")
  {
    $samplingTime = $ARGV[++$i];
  }
  elsif ($arg eq "-noSaveSampledTrace")
  {
    $saveSampledTrace = 0;
  }
  elsif ($arg eq "-inputFilePath")
  {
    $inputFilePath = $ARGV[++$i];
  }
  else
  {
    print "-PacketSinkDlRx : sample PacketSinkDlRx.txt\n";
    print "-PacketSinkUlRx : sample PacketSinkUlRx.txt\n";
    print "-DlPdcpStats : sample DlPdcpStats.txt\n";
    print "-UlPdcpStats : sample UlPdcpStats.txt\n";
    print "-DlTxMac : sample DlTxMac.txt\n";
    print "-UlTxMac : sample UlTxMac.txt\n";
    print "-samplingTime [Ts in seconds]: sampling time (default is 5ms)\n";
    print "-noSaveSampledTrace : do not save the sampled traces\n";
    print "-inputFilePath : where are the traces to read? (With / at the end)\n";
    print "-numOfCc : number of active CCs\n";
    print "\n\n\n";
    die "unknown argument";
  }
}

###############################################################################
#
#                         PACKET SINK TRACES
#
###############################################################################

if ($sampleTrace[0]) # 1. Packets sent by the remote Host and received by the UE
{
  #print "Sample PacketSinkDlRx\n";

  my $filename = $inputFilePath . 'PacketSinkDlRx.txt';
  open(my $fh, '<:encoding(UTF-8)', $filename)
    or die "Could not open file '$filename' $!";

  my @dataRx; # array containing the the rx data for each time instant
  $dataRx[0]=0;
  my $timeCounter=0;
  my @timeAxis; # array containing the time instants
  $timeAxis[0]=$timeCounter*$samplingTime;
  my @instantThroughput; # array containing the instantaneous throughput for
                         # each time instant

  my $row = <$fh>; # get the first row
  chomp $row; # this removes the EOL character
  my($time, $size) = split('\t',$row); # this splits the arguments

  my $numOfRxpackets=0; # this counts the total number of packets

  while ($row)
  {
    #if ($. > 2) # to start from the third line

    #  print "$time\t$size\n"; # this is for debug purposes

      if ($time > $timeCounter*$samplingTime) # this packet belongs to the next time
      {                                       # instant
        $instantThroughput[$timeCounter]=$dataRx[$timeCounter]*8/$samplingTime; # compute the instantaneous
                                                                                      # throughput for this time
                                                                                      # instant
        $timeCounter++; # consider the next time instant
        $timeAxis[$timeCounter]=$timeCounter*$samplingTime; # add the time instat
                                                            # into the time axis
        $dataRx[$timeCounter]=0; # initialize the entry in the rx-data array
      }
      else # this packet belongs to this time instant
      {
        $dataRx[$timeCounter]=$dataRx[$timeCounter]+$size; # add the packet size

        # consider the next packet
        $numOfRxpackets++;
        $row = <$fh>; # this returns false if there are no more rows
        if ($row) # this is used to avoid the warning at the last iteration
        {
          chomp $row;
          ($time, $size) = split('\t',$row); # this returns a warning at the last
                                             # iteration because we are splitting an
                                             # undef value
        }
      }
  }
  close $fh;

  $instantThroughput[$timeCounter]=$dataRx[$timeCounter]*8/$samplingTime; # compute the instantaneous
                                                                          # throughput for the last
                                                                          # time instant

  # compute the average throughput
  my $averageThroughput = 0; # this is used to compute the average Throughput
  for($timeCounter=0; $timeCounter<scalar(@timeAxis); $timeCounter++)
  {
    $averageThroughput+=$instantThroughput[$timeCounter];
  }
  $averageThroughput/=(scalar(@timeAxis)-1); # we do not have to consider the
                                             # first time instant 0
  say $averageThroughput;

  if($saveSampledTrace)
  {
    # Now save the results
    $filename = $inputFilePath . 'PacketSinkDlRx_sampled.txt';
    open($fh, '>:encoding(UTF-8)', $filename)
      or die "Could not open file '$filename' $!";

    for($timeCounter=0; $timeCounter<scalar(@timeAxis); $timeCounter++)
    {
      say $fh "$timeAxis[$timeCounter]\t$dataRx[$timeCounter]\t$instantThroughput[$timeCounter]";
    }
    close $fh;
  }

} # END of 1

#------------------------------------------------------------------------------

if ($sampleTrace[1]) # 2. Packets sent by the UE and received by the remoteHost
{
  #print "Sample PacketSinkUlRx\n";

  my $filename = $inputFilePath . 'PacketSinkUlRx.txt';
  open(my $fh, '<:encoding(UTF-8)', $filename)
    or die "Could not open file '$filename' $!";

  my @dataRx; # array containing the the rx data for each time instant
  $dataRx[0]=0;
  my $timeCounter=0;
  my @timeAxis; # array containing the time instants
  $timeAxis[0]=$timeCounter*$samplingTime;
  my @instantThroughput; # array containing the instantaneous throughput for
                         # each time instant

  my $row = <$fh>; # get the first row
  chomp $row; # this removes the EOL character
  my($time, $size) = split('\t',$row); # this splits the arguments

  my $numOfRxpackets=0; # this counts the total number of packets

  while ($row)
  {
    #if ($. > 2) # to start from the third line

    #  print "$time\t$size\n"; # this is for debug purposes

      if ($time > $timeCounter*$samplingTime) # this packet belongs to the next time
      {                                       # instant
        $instantThroughput[$timeCounter]=$dataRx[$timeCounter]*8/$samplingTime; # compute the instantaneous
                                                                                    # throughput for this time
                                                                                    # instant
        $timeCounter++; # consider the next time instant
        $timeAxis[$timeCounter]=$timeCounter*$samplingTime; # add the time instat
                                                            # into the time axis
        $dataRx[$timeCounter]=0; # initialize the entry in the rx-data array
      }
      else # this packet belongs to this time instant
      {
        $dataRx[$timeCounter]=$dataRx[$timeCounter]+$size; # add the packet size

        # consider the next packet
        $numOfRxpackets++;
        $row = <$fh>; # this returns false if there are no more rows
        if ($row) # this is used to avoid the warning at the last iteration
        {
          chomp $row;
          ($time, $size) = split('\t',$row); # this returns a warning at the last
                                             # iteration because we are splitting an
                                             # undef value
        }
      }
  }
  close $fh;

  $instantThroughput[$timeCounter]=$dataRx[$timeCounter]*8/$samplingTime; # compute the instantaneous
                                                                          # throughput for the last
                                                                          # time instant

  # compute the average throughput
  my $averageThroughput = 0; # this is used to compute the average Throughput
  for($timeCounter=0; $timeCounter<scalar(@timeAxis); $timeCounter++)
  {
    $averageThroughput+=$instantThroughput[$timeCounter];
  }
  $averageThroughput/=(scalar(@timeAxis)-1); # we do not have to consider the
                                             # first time instant 0
  say $averageThroughput;

  if($saveSampledTrace)
  {
    # Now save the results
    $filename = $inputFilePath . 'PacketSinkUlRx_sampled.txt';
    open($fh, '>:encoding(UTF-8)', $filename)
      or die "Could not open file '$filename' $!";

    for($timeCounter=0; $timeCounter<scalar(@timeAxis); $timeCounter++)
    {
      say $fh "$timeAxis[$timeCounter]\t$dataRx[$timeCounter]\t$instantThroughput[$timeCounter]";
    }
    close $fh;
  }

} # END of 2


###############################################################################
#
#                              PDCP TRACES
#
###############################################################################

if ($sampleTrace[2]) # 1. DlPdcpStats: packets sent by the eNB and received by the UE
{
  my $filename = $inputFilePath . 'DlPdcpStats.txt';
  open(my $fh, '<:encoding(UTF-8)', $filename)
    or die "Could not open file '$filename' $!";

  my @dataRx; # array containing the the rx data for each time instant
  $dataRx[0]=0;
  my $timeCounter=0;
  my @timeAxis; # array containing the time instants
  $timeAxis[0]=$timeCounter*$samplingTime;
  my @instantThroughput; # array containing the instantaneous throughput for
                         # each time instant
  my $averageDelay=0; # average delay in nanoseconds

  my $row; # find the first received data packet
  my($mode, $time, $cellId, $imsi, $rnti, $lcid, $size, $delay);
  do
  {
    $row=<$fh>;
    chomp $row; # this removes the EOL character
    ($mode, $time, $cellId, $imsi, $rnti, $lcid, $size, $delay) = split(' ',$row); # this splits the arguments
  }
  while($row && !($mode eq 'Rx' && $lcid>2)); # exit if mode=Rx and it is a data packet
                                              # or if there are no more packets

  my $numOfRxpackets=0; # this counts the total number of packets

  while ($row)
  {
    #if ($. > 2) # to start from the third line

    #  print "$time\t$size\n"; # this is for debug purposes
      if ($time > $timeCounter*$samplingTime) # this packet belongs to the next time
      {                                       # instant
        $instantThroughput[$timeCounter]=$dataRx[$timeCounter]*8/$samplingTime; # compute the instantaneous
                                                                                # throughput for this time
                                                                                # instant
        $timeCounter++; # consider the next time instant
        $timeAxis[$timeCounter]=$timeCounter*$samplingTime; # add the time instat
                                                            # into the time axis
        $dataRx[$timeCounter]=0; # initialize the entry in the rx-data array
      }
      else # this packet belongs to this time instant
      {
        $dataRx[$timeCounter]=$dataRx[$timeCounter]+$size; # add the packet size
        $averageDelay+=$delay;
        $numOfRxpackets++;
        # find the next received packet
        do
        {
          $row = <$fh>; # this returns false if there are no more rows
          if ($row) # this is used to avoid the warning at the last iteration
          {
            chomp $row;
            ($mode, $time, $cellId, $imsi, $rnti, $lcid, $size, $delay) = split(' ',$row); # this splits the arguments
                                                                                       # this returns a warning at the last
                                                                                       # iteration because we are splitting an
                                                                                       # undef value
          }
        }
        while($row && !($mode eq 'Rx' && $lcid>2)); # exit if mode=Rx and it is a data packet
                                                    # or if there are no more packets
      }
  }
  close $fh;

  $instantThroughput[$timeCounter]=$dataRx[$timeCounter]*8/$samplingTime; # compute the instantaneous
                                                                          # throughput for the last
                                                                          # time instant
  # compute the average delay
  $averageDelay/=$numOfRxpackets;

  # compute the average throughput
  my $averageThroughput = 0; # this is used to compute the average Throughput
  for($timeCounter=0; $timeCounter<scalar(@timeAxis); $timeCounter++)
  {
    $averageThroughput+=$instantThroughput[$timeCounter];
  }
  $averageThroughput/=(scalar(@timeAxis)-1); # we do not have to consider the
                                             # first time instant 0
  say "avg throughput [bps]\tavg delay [ns]\tnum rx pcks";
  say "$averageThroughput\t$averageDelay\t$numOfRxpackets";

  if($saveSampledTrace)
  {
    # Now save the results
    $filename = $inputFilePath . 'DlPdcpStats_sampled.txt';
    open($fh, '>:encoding(UTF-8)', $filename)
      or die "Could not open file '$filename' $!";

    for($timeCounter=0; $timeCounter<scalar(@timeAxis); $timeCounter++)
    {
      say $fh "$timeAxis[$timeCounter]\t$dataRx[$timeCounter]\t$instantThroughput[$timeCounter]";
    }
    close $fh;
  }
}

if ($sampleTrace[3]) # 2. UlPdcpStats: packets sent by the UE and received by the eNB
{
  my $filename = $inputFilePath . 'UlPdcpStats.txt';
  open(my $fh, '<:encoding(UTF-8)', $filename)
    or die "Could not open file '$filename' $!";

  my @dataRx; # array containing the the rx data for each time instant
  $dataRx[0]=0;
  my $timeCounter=0;
  my @timeAxis; # array containing the time instants
  $timeAxis[0]=$timeCounter*$samplingTime;
  my @instantThroughput; # array containing the instantaneous throughput for
                         # each time instant
  my $averageDelay=0; # average delay in nanoseconds

  my $row; # find the first received data packet
  my($mode, $time, $cellId, $imsi, $rnti, $lcid, $size, $delay);
  do
  {
    $row=<$fh>;
    chomp $row; # this removes the EOL character
    ($mode, $time, $cellId, $imsi, $rnti, $lcid, $size, $delay) = split(' ',$row); # this splits the arguments
  }
  while($row && !($mode eq 'Rx' && $lcid>2)); # exit if mode=Rx and it is a data packet
                                              # or if there are no more packets

  my $numOfRxpackets=0; # this counts the total number of packets

  while ($row)
  {
    #if ($. > 2) # to start from the third line

    #  print "$time\t$size\n"; # this is for debug purposes
      if ($time > $timeCounter*$samplingTime) # this packet belongs to the next time
      {                                       # instant
        $instantThroughput[$timeCounter]=$dataRx[$timeCounter]*8/$samplingTime; # compute the instantaneous
                                                                                # throughput for this time
                                                                                # instant
        $timeCounter++; # consider the next time instant
        $timeAxis[$timeCounter]=$timeCounter*$samplingTime; # add the time instat
                                                            # into the time axis
        $dataRx[$timeCounter]=0; # initialize the entry in the rx-data array
      }
      else # this packet belongs to this time instant
      {
        $dataRx[$timeCounter]=$dataRx[$timeCounter]+$size; # add the packet size
        $averageDelay+=$delay;
        $numOfRxpackets++;
        # find the next received packet
        do
        {
          $row = <$fh>; # this returns false if there are no more rows
          if ($row) # this is used to avoid the warning at the last iteration
          {
            chomp $row;
            ($mode, $time, $cellId, $imsi, $rnti, $lcid, $size, $delay) = split(' ',$row); # this splits the arguments
                                                                                       # this returns a warning at the last
                                                                                       # iteration because we are splitting an
                                                                                       # undef value
          }
        }
        while($row && !($mode eq 'Rx' && $lcid>2)); # exit if mode=Rx and it is a data packet
                                                    # or if there are no more packets
      }
  }
  close $fh;

  $instantThroughput[$timeCounter]=$dataRx[$timeCounter]*8/$samplingTime; # compute the instantaneous
                                                                          # throughput for the last
                                                                          # time instant
  # compute the average delay
  $averageDelay/=$numOfRxpackets;

  # compute the average throughput
  my $averageThroughput = 0; # this is used to compute the average Throughput
  for($timeCounter=0; $timeCounter<scalar(@timeAxis); $timeCounter++)
  {
    $averageThroughput+=$instantThroughput[$timeCounter];
  }
  $averageThroughput/=(scalar(@timeAxis)-1); # we do not have to consider the
                                             # first time instant 0
  say "avg throughput [bps]\tavg delay [ns]\tnum rx pcks";
  say "$averageThroughput\t$averageDelay\t$numOfRxpackets";

  if($saveSampledTrace)
  {
    # Now save the results
    $filename = $inputFilePath . 'UlPdcpStats_sampled.txt';
    open($fh, '>:encoding(UTF-8)', $filename)
      or die "Could not open file '$filename' $!";

    for($timeCounter=0; $timeCounter<scalar(@timeAxis); $timeCounter++)
    {
      say $fh "$timeAxis[$timeCounter]\t$dataRx[$timeCounter]\t$instantThroughput[$timeCounter]";
    }
    close $fh;
  }
}

###############################################################################
#
#                              MAC TRACES
#
###############################################################################

# test CC0 4743504 CC1 2199440
if ($sampleTrace[4]) # 1. DlTxMac: packets sent by the eNB
{
  #print "Sample PacketSinkUlRx\n";

  my $filename = $inputFilePath . 'DlTxMac.txt';
  open(my $fh, '<:encoding(UTF-8)', $filename)
    or die "Could not open file '$filename' $!";

  my @dataRx; # matrix, each row is associated to a CC
              # Each row contains the the rx data for each time instant

  for(my $cc=0; $cc<$numOfActiveCc; $cc++)
  {
    $dataRx[$cc][0]=0; # CC0
  }

  my $timeCounter=0;
  my @timeAxis; # array containing the time instants
  $timeAxis[0]=$timeCounter*$samplingTime;
  my @instantThroughput; # array containing the instantaneous throughput for
                         # each time instant

  my $row = <$fh>; # get the first row
  chomp $row; # this removes the EOL character
  my($time, $rnti, $ccId, $size) = split('\t',$row); # this splits the arguments

  my @numOfRxpackets;
  for(my $cc=0; $cc<$numOfActiveCc; $cc++)
  {
    $numOfRxpackets[$cc]=0; # this counts the total number of packets sent by CCcc
  }

  while ($row)
  {
    #if ($. > 2) # to start from the third line

    #  print "$time\t$size\n"; # this is for debug purposes

      if ($time > $timeCounter*$samplingTime) # this packet belongs to the next time
      {                                       # instant
        # compute the instantaneous throughput for this time instant
        for(my $cc=0; $cc<$numOfActiveCc; $cc++)
        {
          $instantThroughput[$cc][$timeCounter]=$dataRx[$cc][$timeCounter]*8/$samplingTime;
        }

        $timeCounter++; # consider the next time instant
        $timeAxis[$timeCounter]=$timeCounter*$samplingTime; # add the time instat
                                                            # into the time axis
        # initialize the entry in the rx-data array
        for(my $cc=0; $cc<$numOfActiveCc; $cc++)
        {
          $dataRx[$cc][$timeCounter]=0;
        }
      }
      else # this packet belongs to this time instant
      {
        if ($ccId >= $numOfActiveCc)
        {
          die "The number of active CCs was not correctly set";
        }
        $dataRx[$ccId][$timeCounter]=$dataRx[$ccId][$timeCounter]+$size; # add the packet size

        # consider the next packet
        $numOfRxpackets[$ccId]++;
        $row = <$fh>; # this returns false if there are no more rows
        if ($row) # this is used to avoid the warning at the last iteration
        {
          chomp $row;
          ($time, $rnti, $ccId, $size) = split('\t',$row); # this returns a warning at the last
                                                           # iteration because we are splitting an
                                                           # undef value
        }
      }
  }
  close $fh;

  for(my $cc=0; $cc<$numOfActiveCc; $cc++)
  {
    $instantThroughput[$cc][$timeCounter]=$dataRx[$cc][$timeCounter]*8/$samplingTime; # compute the instantaneous
                                                                                  # throughput for the last
                                                                                  # time instant
  }

  # compute the average throughput
  my @averageThroughput;
  for(my $cc=0; $cc<$numOfActiveCc; $cc++)
  {
    $averageThroughput[$cc] = 0; # this is used to compute the average Throughput
  }

  for($timeCounter=0; $timeCounter<scalar(@timeAxis); $timeCounter++)
  {
    for(my $cc=0; $cc<$numOfActiveCc; $cc++)
    {
      $averageThroughput[$cc]+=$instantThroughput[$cc][$timeCounter];
    }
  }
  for(my $cc=0; $cc<$numOfActiveCc; $cc++)
  {
    $averageThroughput[$cc]/=(scalar(@timeAxis)-1); # we do not have to consider the
                                                   # first time instant 0
    print "$averageThroughput[$cc]\t";
  }
  print "\n";

  if($saveSampledTrace)
  {
    # Now save the results
    $filename = $inputFilePath . 'DlTxMac_sampled.txt';
    open($fh, '>:encoding(UTF-8)', $filename)
      or die "Could not open file '$filename' $!";

    for($timeCounter=0; $timeCounter<scalar(@timeAxis); $timeCounter++)
    {
      print $fh "$timeAxis[$timeCounter]\t";
      for(my $cc=0; $cc<$numOfActiveCc; $cc++)
      {
        print $fh "$dataRx[$cc][$timeCounter]\t$instantThroughput[$cc][$timeCounter]\t";
      }
      print $fh "\n";
    }
    close $fh;
  }
} # END 1

if ($sampleTrace[5]) # 2. UlTxMac: packets sent by the UE
{
  #print "Sample PacketSinkUlRx\n";

  my $filename = $inputFilePath . 'UlTxMac.txt';
  open(my $fh, '<:encoding(UTF-8)', $filename)
    or die "Could not open file '$filename' $!";

  my @dataRx; # matrix, each row is associated to a CC
              # Each row contains the the rx data for each time instant

  for(my $cc=0; $cc<$numOfActiveCc; $cc++)
  {
    $dataRx[$cc][0]=0; # CC0
  }

  my $timeCounter=0;
  my @timeAxis; # array containing the time instants
  $timeAxis[0]=$timeCounter*$samplingTime;
  my @instantThroughput; # array containing the instantaneous throughput for
                         # each time instant

  my $row = <$fh>; # get the first row
  chomp $row; # this removes the EOL character
  my($time, $rnti, $ccId, $size) = split('\t',$row); # this splits the arguments

  my @numOfRxpackets;
  for(my $cc=0; $cc<$numOfActiveCc; $cc++)
  {
    $numOfRxpackets[$cc]=0; # this counts the total number of packets sent by CCcc
  }

  while ($row)
  {
    #if ($. > 2) # to start from the third line

    #  print "$time\t$size\n"; # this is for debug purposes

      if ($time > $timeCounter*$samplingTime) # this packet belongs to the next time
      {                                       # instant
        # compute the instantaneous throughput for this time instant
        for(my $cc=0; $cc<$numOfActiveCc; $cc++)
        {
          $instantThroughput[$cc][$timeCounter]=$dataRx[$cc][$timeCounter]*8/$samplingTime;
        }

        $timeCounter++; # consider the next time instant
        $timeAxis[$timeCounter]=$timeCounter*$samplingTime; # add the time instat
                                                            # into the time axis
        # initialize the entry in the rx-data array
        for(my $cc=0; $cc<$numOfActiveCc; $cc++)
        {
          $dataRx[$cc][$timeCounter]=0;
        }
      }
      else # this packet belongs to this time instant
      {
        if ($ccId >= $numOfActiveCc)
        {
          die "The number of active CCs was not correctly set";
        }
        $dataRx[$ccId][$timeCounter]=$dataRx[$ccId][$timeCounter]+$size; # add the packet size

        # consider the next packet
        $numOfRxpackets[$ccId]++;
        $row = <$fh>; # this returns false if there are no more rows
        if ($row) # this is used to avoid the warning at the last iteration
        {
          chomp $row;
          ($time, $rnti, $ccId, $size) = split('\t',$row); # this returns a warning at the last
                                                           # iteration because we are splitting an
                                                           # undef value
        }
      }
  }
  close $fh;

  for(my $cc=0; $cc<$numOfActiveCc; $cc++)
  {
    $instantThroughput[$cc][$timeCounter]=$dataRx[$cc][$timeCounter]*8/$samplingTime; # compute the instantaneous
                                                                                  # throughput for the last
                                                                                  # time instant
  }

  # compute the average throughput
  my @averageThroughput;
  for(my $cc=0; $cc<$numOfActiveCc; $cc++)
  {
    $averageThroughput[$cc] = 0; # this is used to compute the average Throughput
  }

  for($timeCounter=0; $timeCounter<scalar(@timeAxis); $timeCounter++)
  {
    for(my $cc=0; $cc<$numOfActiveCc; $cc++)
    {
      $averageThroughput[$cc]+=$instantThroughput[$cc][$timeCounter];
    }
  }
  for(my $cc=0; $cc<$numOfActiveCc; $cc++)
  {
    $averageThroughput[$cc]/=(scalar(@timeAxis)-1); # we do not have to consider the
                                                   # first time instant 0
    print "$averageThroughput[$cc]\t";
  }
  print "\n";

  if($saveSampledTrace)
  {
    # Now save the results
    $filename = $inputFilePath . 'UlTxMac_sampled.txt';
    open($fh, '>:encoding(UTF-8)', $filename)
      or die "Could not open file '$filename' $!";

    for($timeCounter=0; $timeCounter<scalar(@timeAxis); $timeCounter++)
    {
      print $fh "$timeAxis[$timeCounter]\t";
      for(my $cc=0; $cc<$numOfActiveCc; $cc++)
      {
        print $fh "$dataRx[$cc][$timeCounter]\t$instantThroughput[$cc][$timeCounter]\t";
      }
      print $fh "\n";
    }
    close $fh;
  }
} # END 2

###############################################################################
#
#                              RLC TRACES
#
###############################################################################

if ($sampleTrace[6]) # 1. DlRlcStats: packets sent by the eNB and received by the UE
{
  my $filename = $inputFilePath . 'DlRlcStats.txt';
  open(my $fh, '<:encoding(UTF-8)', $filename)
    or die "Could not open file '$filename' $!";

  my @dataRx; # array containing the the rx data for each time instant
  $dataRx[0]=0;
  my $timeCounter=0;
  my @timeAxis; # array containing the time instants
  $timeAxis[0]=$timeCounter*$samplingTime;
  my @instantThroughput; # array containing the instantaneous throughput for
                         # each time instant
  my $averageDelay=0; # average delay in nanoseconds

  my $row; # find the first received data packet
  my($mode, $time, $cellId, $imsi, $rnti, $lcid, $size, $delay);
  do
  {
    $row=<$fh>;
    chomp $row; # this removes the EOL character
    ($mode, $time, $cellId, $imsi, $rnti, $lcid, $size, $delay) = split(' ',$row); # this splits the arguments
  }
  while($row && !($mode eq 'Rx' && $lcid>2)); # exit if mode=Rx and it is a data packet
                                              # or if there are no more packets

  my $numOfRxpackets=0; # this counts the total number of packets

  while ($row)
  {
    #if ($. > 2) # to start from the third line

    #  print "$time\t$size\n"; # this is for debug purposes
      if ($time > $timeCounter*$samplingTime) # this packet belongs to the next time
      {                                       # instant
        $instantThroughput[$timeCounter]=$dataRx[$timeCounter]*8/$samplingTime; # compute the instantaneous
                                                                                # throughput for this time
                                                                                # instant
        $timeCounter++; # consider the next time instant
        $timeAxis[$timeCounter]=$timeCounter*$samplingTime; # add the time instat
                                                            # into the time axis
        $dataRx[$timeCounter]=0; # initialize the entry in the rx-data array
      }
      else # this packet belongs to this time instant
      {
        $dataRx[$timeCounter]=$dataRx[$timeCounter]+$size; # add the packet size
        $averageDelay+=$delay;
        $numOfRxpackets++;
        # find the next received packet
        do
        {
          $row = <$fh>; # this returns false if there are no more rows
          if ($row) # this is used to avoid the warning at the last iteration
          {
            chomp $row;
            ($mode, $time, $cellId, $imsi, $rnti, $lcid, $size, $delay) = split(' ',$row); # this splits the arguments
                                                                                       # this returns a warning at the last
                                                                                       # iteration because we are splitting an
                                                                                       # undef value
          }
        }
        while($row && !($mode eq 'Rx' && $lcid>2)); # exit if mode=Rx and it is a data packet
                                                    # or if there are no more packets
      }
  }
  close $fh;

  $instantThroughput[$timeCounter]=$dataRx[$timeCounter]*8/$samplingTime; # compute the instantaneous
                                                                          # throughput for the last
                                                                          # time instant
  # compute the average delay
  $averageDelay/=$numOfRxpackets;

  # compute the average throughput
  my $averageThroughput = 0; # this is used to compute the average Throughput
  for($timeCounter=0; $timeCounter<scalar(@timeAxis); $timeCounter++)
  {
    $averageThroughput+=$instantThroughput[$timeCounter];
  }
  $averageThroughput/=(scalar(@timeAxis)-1); # we do not have to consider the
                                             # first time instant 0
  say "avg throughput [bps]\tavg delay [ns]\tnum rx pcks";  
  say "$averageThroughput\t$averageDelay\t$numOfRxpackets";

  if($saveSampledTrace)
  {
    # Now save the results
    $filename = $inputFilePath . 'DlRlcStats_sampled.txt';
    open($fh, '>:encoding(UTF-8)', $filename)
      or die "Could not open file '$filename' $!";

    for($timeCounter=0; $timeCounter<scalar(@timeAxis); $timeCounter++)
    {
      say $fh "$timeAxis[$timeCounter]\t$dataRx[$timeCounter]\t$instantThroughput[$timeCounter]";
    }
    close $fh;
  }
} # END 1

if ($sampleTrace[7]) # 2. UlRlcStats: packets sent by the UE and received by the eNB
{
  my $filename = $inputFilePath . 'UlRlcStats.txt';
  open(my $fh, '<:encoding(UTF-8)', $filename)
    or die "Could not open file '$filename' $!";

  my @dataRx; # array containing the the rx data for each time instant
  $dataRx[0]=0;
  my $timeCounter=0;
  my @timeAxis; # array containing the time instants
  $timeAxis[0]=$timeCounter*$samplingTime;
  my @instantThroughput; # array containing the instantaneous throughput for
                         # each time instant
  my $averageDelay=0; # average delay in nanoseconds

  my $row; # find the first received data packet
  my($mode, $time, $cellId, $imsi, $rnti, $lcid, $size, $delay);
  do
  {
    $row=<$fh>;
    chomp $row; # this removes the EOL character
    ($mode, $time, $cellId, $imsi, $rnti, $lcid, $size, $delay) = split(' ',$row); # this splits the arguments
  }
  while($row && !($mode eq 'Rx' && $lcid>2)); # exit if mode=Rx and it is a data packet
                                              # or if there are no more packets

  my $numOfRxpackets=0; # this counts the total number of packets

  while ($row)
  {
    #if ($. > 2) # to start from the third line

    #  print "$time\t$size\n"; # this is for debug purposes
      if ($time > $timeCounter*$samplingTime) # this packet belongs to the next time
      {                                       # instant
        $instantThroughput[$timeCounter]=$dataRx[$timeCounter]*8/$samplingTime; # compute the instantaneous
                                                                                # throughput for this time
                                                                                # instant
        $timeCounter++; # consider the next time instant
        $timeAxis[$timeCounter]=$timeCounter*$samplingTime; # add the time instat
                                                            # into the time axis
        $dataRx[$timeCounter]=0; # initialize the entry in the rx-data array
      }
      else # this packet belongs to this time instant
      {
        $dataRx[$timeCounter]=$dataRx[$timeCounter]+$size; # add the packet size
        $averageDelay+=$delay;
        $numOfRxpackets++;
        # find the next received packet
        do
        {
          $row = <$fh>; # this returns false if there are no more rows
          if ($row) # this is used to avoid the warning at the last iteration
          {
            chomp $row;
            ($mode, $time, $cellId, $imsi, $rnti, $lcid, $size, $delay) = split(' ',$row); # this splits the arguments
                                                                                       # this returns a warning at the last
                                                                                       # iteration because we are splitting an
                                                                                       # undef value
          }
        }
        while($row && !($mode eq 'Rx' && $lcid>2)); # exit if mode=Rx and it is a data packet
                                                    # or if there are no more packets
      }
  }
  close $fh;

  $instantThroughput[$timeCounter]=$dataRx[$timeCounter]*8/$samplingTime; # compute the instantaneous
                                                                          # throughput for the last
                                                                          # time instant
  # compute the average delay
  $averageDelay/=$numOfRxpackets;

  # compute the average throughput
  my $averageThroughput = 0; # this is used to compute the average Throughput
  for($timeCounter=0; $timeCounter<scalar(@timeAxis); $timeCounter++)
  {
    $averageThroughput+=$instantThroughput[$timeCounter];
  }
  $averageThroughput/=(scalar(@timeAxis)-1); # we do not have to consider the
                                             # first time instant 0
  say "avg throughput [bps]\tavg delay [ns]\tnum rx pcks";
  say "$averageThroughput\t$averageDelay\t$numOfRxpackets";

  if($saveSampledTrace)
  {
    # Now save the results
    $filename = $inputFilePath . 'UlRlcStats_sampled.txt';
    open($fh, '>:encoding(UTF-8)', $filename)
      or die "Could not open file '$filename' $!";

    for($timeCounter=0; $timeCounter<scalar(@timeAxis); $timeCounter++)
    {
      say $fh "$timeAxis[$timeCounter]\t$dataRx[$timeCounter]\t$instantThroughput[$timeCounter]";
    }
    close $fh;
  }
} # END 2
