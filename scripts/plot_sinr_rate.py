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
        self.rate = np.zeros(nlines) 
        self.sinrAvg = np.zeros(nint)
        self.rateAvg = np.zeros(nint)
    frameNum = np.zeros(0)
    sfNum = np.zeros(0)
    sinr = np.zeros(0) 
    mcs = np.zeros(0)
    size = np.zeros(0) 
    tbler = np.zeros(0)
    corrupt = np.zeros(0)
    rate = np.zeros(0)
    sinrAvg = np.zeros(0)
    rateAvg = np.zeros(0)


# class RateTraceDat:
#     def __init__(self,nlines,nint,timeToAvg):
#         self.timestamp = np.zeros(nlines) 
#         self.size = np.zeros(nlines)
#         self.rate = np.zeros(nint)
#         self.sinr = np.zeros(nint)
#         self.intStart = np.arange(0,nint*timeToAvg,timeToAvg)

csvDir = '../amc_data'
traceFiles = ['fading_harq.tr']#,'DlRlcStats.txt','UlPdcpStats.txt','UlRlcStats.txt']
parsedFiles = ['sinr_rate_awgn_noharq.dat','sinr_rate_awgn_harq.dat','sinr_rate_fading_noharq.dat'] # data files we have already parsed

traces = ['UlRxTrace']
datMap = {};
#linesToAvg = 5000
linesToAvg = 63000 # average over 63 s intervals 
tsLast = 0.0    # timestamp of last entry
sfInt = 100e-6 # 100us subframe
rateScale = 1e-6
itrace = 0;
lineSkip = 1;

for file in parsedFiles:
    csvPath = csvDir + "/" + file
    cmdWc = 'cat ' + csvPath + ' | wc -l'  # line count command
    c = os.popen(cmdWc)
    numLines = int(c.read().rstrip())
    dat = PhyTraceDat(0,numLines-lineSkip)
    line = 0
    with open(csvPath, 'rb') as csvFile:
        reader = csv.reader(csvFile, delimiter=' ')
        try:
            for row in reader:
                if (line >= lineSkip):
                    dat.sinrAvg[line-lineSkip] = row[0]
                    dat.rateAvg[line-lineSkip] = row[1]
                line += 1
                if (line == numLines):
                    break
        except csv.Error as e:
            sys.exit('file %s, line %d: %s' % (csvPath, reader.line_num, e))
        datMap[file] = dat
                
for file in traceFiles:
    csvPath = csvDir + "/" + file
    cmdWc = 'grep ' + traces[itrace] + ' ' + csvPath + ' | wc -l'  # line count command
    c = os.popen(cmdWc)
    numLines = int(c.read().rstrip())       # count lines
    numInt = int(math.ceil(numLines / linesToAvg))
    print str(numLines) + " lines " + str(numInt) + " intervals"
    
    dat = PhyTraceDat(numLines,numInt)
        
    line = 0
    intIdx = 0  
    intLineLast = linesToAvg;
    with open(csvPath, 'rb') as csvFile:
        reader = csv.reader(csvFile, delimiter='\t')
        try:
            for row in reader:
                if(len(row) == 13 and row[0] == traces[itrace]): 
                    if (line >= intLineLast):
                        dat.sinrAvg[intIdx] = 10*math.log10(dat.sinrAvg[intIdx] / linesToAvg)
                        dat.rateAvg[intIdx] = 8 * dat.rateAvg[intIdx] * rateScale / (sfInt * linesToAvg)
                        print str(dat.sinrAvg[intIdx]) + " " + str(dat.rateAvg[intIdx])
                        intIdx += 1
                        if (intIdx == numInt):
                            break
                        intLineLast += linesToAvg
                    dat.sinrAvg[intIdx] += float(row[9])
                    dat.rateAvg[intIdx] += float(row[6]) * (1.0 - float(row[11]))
                line += 1
        except csv.Error as e:
            sys.exit('file %s, line %d: %s' % (csvPath, reader.line_num, e))
    datMap[file] = dat    
# fig1 = plt.figure()
# ax1 = fig1.add_subplot(111)
# #t = np.arange(0.0,tsLast,timeToAvg)
# dat = datMap[phyFiles[0]]
# #n = min(len(dat.intStart),len(dat.rate))
# ax1.plot(dat.sinrAvg)
# #ax1.legend(bbox_to_anchor=(0.4, 1.0))
# ax1.set_xlabel('Time (s)')
# ax1.set_ylabel('SINR (dB)')
# plt.show()    

allFiles = parsedFiles + traceFiles

fig1 = plt.figure()
ax1 = fig1.add_subplot(111)
for file in allFiles:
    dat = datMap[file]
    n = min(len(dat.sinrAvg),len(dat.rateAvg))
    ax1.plot(dat.sinrAvg[0:n],dat.rateAvg[0:n])
#ax1.legend(bbox_to_anchor=(0.4, 1.0))
ax1.set_xlabel('SINR (dB)')
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

