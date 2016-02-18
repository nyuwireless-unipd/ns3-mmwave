import csv
import numpy as np
import pylab
import matplotlib.pyplot as plt
import os
import math
import re

class PhyTraceDat:
    def __init__(self,nlines,nint):
        self.frameNum = np.zeros(nlines) 
        self.sfNum = np.zeros(nlines)
        self.sinr = np.zeros(nlines) 
        self.mcs = np.zeros(nlines)
        self.size = np.zeros(nlines) 
        self.tbler = np.zeros(nlines)
        self.corrupt = np.zeros(nlines)
        self.rate = np.zeros(nint) # num intervals 
    
class RateTraceDat:
    def __init__(self,id,nlines,nint,timeToAvg):
        self.rnti = id
        self.timestamp = np.zeros(nlines) 
        self.size = np.zeros(nlines)
        self.rate = np.zeros(nint)
        self.intStart = np.arange(0,nint*timeToAvg,timeToAvg)

csvDir = '.'
pdcpRlcFiles = ['DlRlcStats.txt']#,'DlRlcStats.txt','UlPdcpStats.txt','UlRlcStats.txt']
traces = ['DlRxPDU','DlRxPDU','UlRxPDU','UlRxPDU']
datMap = {};
timeToAvg = 1e-3 # average over 1 ms intervals 
tsLast = 0.0    # timestamp of last entry
numUsers = 20

itrace = 0;
for file in pdcpRlcFiles:
    csvPath = csvDir + "/" + file
    cmdWc = 'grep ' + traces[itrace] + ' ' + csvPath + ' | wc -l'
    c = os.popen(cmdWc)
    numLines = int(c.read().rstrip())       # count lines
    
    cmdGetTsLast = 'tail ' + csvPath + ' -n1 | gawk \'match($0, /\+(.*)ns/, matches) {print matches[1]}\''
    c = os.popen(cmdGetTsLast)
    tsLast = float(c.read().rstrip()) / 1e9
    numInt = int(math.ceil(tsLast / timeToAvg)) + 1
    print str(tsLast) + " " + str(numInt)
    userRateDat = [ RateTraceDat(i,numLines,numInt,timeToAvg) for i in range(0,numUsers+1) ]
    #dat = RateTraceDat(numLines,numInt,timeToAvg)
    line = 0
    intIdx = 0
    intTs0 = 0.0
    with open(csvPath, 'rb') as csvFile:
        reader = csv.reader(csvFile, delimiter=' ')
        for row in reader:
            rnti = int(row[4])
            if(row[1] == traces[itrace] and rnti <= numUsers): 
                dat = userRateDat[rnti]
                match = re.search('\+(.*)ns', row[2])  
                if (match.group(0) != 'None'):
                    dat.timestamp[line] = float(match.group(1))/1e9  # get time in seconds
                    #print dat.timestamp[line]
                else:
                    print "No Match"
                dat.size[line] = int(row[6])
                while (1):
                    if (intIdx == numInt):
                        break      
                    if ((intIdx == 0 or (dat.timestamp[line] >= dat.intStart[intIdx-1])) and (intIdx == numInt-1 or (dat.timestamp[line] < dat.intStart[intIdx]))):
                        dat.rate[intIdx] += dat.size[line]
                        break
                    else:
                        intIdx = intIdx + 1
                line = line + 1
                if (line == numLines):
                    break
    for i in range(0,numUsers+1):        
        userRateDat[i].rate = ((8*userRateDat[i].rate) / (timeToAvg)) * 1e-6
        print "UE " + str(i) + " avg rate " + str(np.mean(userRateDat[i].rate[userRateDat[i].rate!=0])) + " Mbps"
    datMap['DlRxPDU'] = userRateDat    

# for i in range(0,len(dat.intStart)-1):
#     print str(dat.intStart[i]) + ' ' + str(dat.rate[i]) 
fig1 = plt.figure()
ax1 = fig1.add_subplot(111)
#t = np.arange(0.0,tsLast,timeToAvg)
dat = datMap['DlRxPDU']
n = min(len(dat[1].intStart),len(dat[1].rate))
ax1.plot(dat[1].intStart[0:n],dat[1].rate[0:n])
#ax1.legend(bbox_to_anchor=(0.4, 1.0))
ax1.set_xlabel('Time (s)')
ax1.set_ylabel('Rate (Mbps)')
plt.show()    

#                 
# phyTraces = 'RxPacektTrace.txt'
# 
# csvPath = csvDir + "/" + file
# cmdWc = 'grep ' + traces[itrace] + ' ' + csvPath + ' | wc -l'
# c = os.popen(cmdWc)
# numLines = int(c.read().rstrip())       # count lines
# framePeriod = numFramesToAvg * 1.0E-3
# rateScale = 8 * 1.0E-6 / framePeriod
# 
# dat = TraceDat(numLines)
# lineIdx = 0
# with open(csvPath, 'rb') as csvFile:
#     reader = csv.reader(csvFile, delimiter='\t')
#     try:
#         for row in reader:
#             if(len(row) == 11 and row[0] == trace):             
#                 #frameIdx = math.floor(int(row[1])/numFramesToAvg)
#                 dat.frameNum[lineIdx] = int(row[1])
#                 dat.sfNum[lineIdx] = int(row[2])
#                 dat.corrupt[lineIdx] = int(row[10]) 
#                 dat.tbler[lineIdx] = float(row[9])
#                     if (not dat.corrupt[lineIdx]):
#                         dat.rate[lineIdx] = int(row[5])
#                     dat.mcs[lineIdx] = int(row[6])
#                     dat.sinr[lineIdx] = round(10*math.log10(float(row[8])),3)
# 
# numFlows = [10,20,50,100]
# 
# yticks = [0,1,5,10,25]
# lineStyle = ['*-','.-','x-','d-','s-','o-']
# tstListDl = ['fixed 50us sf','fixed 100us sf','fixed 200us sf','var 50us sf','var 200us sf','var 100us sf',]
# istyle = 0
# for tst in tstListDl:
#     plt.semilogy(numFlows,tstDatDl[tst],lineStyle[istyle],label=tst)
#     istyle = istyle + 1
# plt.legend(bbox_to_anchor=(0.4, 1.1))
# #plt.yticks(yticks)
# plt.title('')
# # pylab.text(0, 0, txJitterLabel, fontsize=12)
# plt.xlabel("Num DL flows")
# plt.ylabel("Mean PDCP latency (ms)")
# plt.show()  
# 
# yticks = [0,0.5,1,5]
# istyle = 0
# tstListUl = ['fixed 50us sf','fixed 200us sf','fixed 100us sf','var 200us sf','var 100us sf','var 50us sf',] 
# for tst in tstListUl:
#     plt.semilogy(numFlows,tstDatUl[tst],lineStyle[istyle],label=tst)
#     istyle = istyle + 1
# plt.legend(bbox_to_anchor=(0.4, 1.1))
# #plt.yticks(yticks)
# plt.title('')
# # pylab.text(0, 0, txJitterLabel, fontsize=12)
# plt.xlabel("Num UL flows")
# plt.ylabel("Mean PDCP latency (ms)")
# plt.show()    
#       
#     

