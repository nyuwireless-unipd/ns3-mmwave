import csv
import numpy as np
import pylab
import matplotlib.pyplot as plt
import os
import math
from collections import defaultdict

tstFileDlVar = {}
tstFileUlVar = {}
tstFileDlFixed = {}
tstFileUlFixed = {}

tstDatDl = defaultdict(list)
tstDatUl = defaultdict(list)

tstFileDlVar['var 50us sf'] = ['DlPdcpStats_10ue_50sf.tr','DlPdcpStats_20ue_50sf.tr','DlPdcpStats_50ue_50sf.tr','DlPdcpStats_100ue_50sf.tr']
tstFileDlVar['var 100us sf'] = ['DlPdcpStats_10ue_100sf.tr','DlPdcpStats_20ue_100sf.tr','DlPdcpStats_50ue_100sf.tr','DlPdcpStats_100ue_100sf.tr']
tstFileDlVar['var 200us sf'] = ['DlPdcpStats_10ue_200sf.tr','DlPdcpStats_20ue_200sf.tr','DlPdcpStats_50ue_200sf.tr','DlPdcpStats_100ue_200sf.tr']

tstFileUlVar['var 50us sf'] = ['UlPdcpStats_10ue_50sf.tr','UlPdcpStats_20ue_50sf.tr','UlPdcpStats_50ue_50sf.tr','UlPdcpStats_100ue_50sf.tr']
tstFileUlVar['var 100us sf'] = ['UlPdcpStats_10ue_100sf.tr','UlPdcpStats_20ue_100sf.tr','UlPdcpStats_50ue_100sf.tr','UlPdcpStats_100ue_100sf.tr']
tstFileUlVar['var 200us sf'] = ['UlPdcpStats_10ue_200sf.tr','UlPdcpStats_20ue_200sf.tr','UlPdcpStats_50ue_200sf.tr','UlPdcpStats_100ue_200sf.tr']

tstFileDlFixed['fixed 50us sf'] = ['DlPdcpStats_10ue_50sf_fixed.tr','DlPdcpStats_20ue_50sf_fixed.tr','DlPdcpStats_50ue_50sf_fixed.tr','DlPdcpStats_100ue_50sf_fixed.tr']
tstFileDlFixed['fixed 100us sf'] = ['DlPdcpStats_10ue_100sf_fixed.tr','DlPdcpStats_20ue_100sf_fixed.tr','DlPdcpStats_50ue_100sf_fixed.tr','DlPdcpStats_100ue_100sf_fixed.tr']
tstFileDlFixed['fixed 200us sf']= ['DlPdcpStats_10ue_200sf_fixed.tr','DlPdcpStats_20ue_200sf_fixed.tr','DlPdcpStats_50ue_200sf_fixed.tr','DlPdcpStats_100ue_200sf_fixed.tr']

tstFileUlFixed['fixed 50us sf'] = ['UlPdcpStats_10ue_50sf_fixed.tr','UlPdcpStats_20ue_50sf_fixed.tr','UlPdcpStats_50ue_50sf_fixed.tr','UlPdcpStats_100ue_50sf_fixed.tr']
tstFileUlFixed['fixed 100us sf'] = ['UlPdcpStats_10ue_100sf_fixed.tr','UlPdcpStats_20ue_100sf_fixed.tr','UlPdcpStats_50ue_100sf_fixed.tr','UlPdcpStats_100ue_100sf_fixed.tr']
tstFileUlFixed['fixed 200us sf'] = ['UlPdcpStats_10ue_200sf_fixed.tr','UlPdcpStats_20ue_200sf_fixed.tr','UlPdcpStats_50ue_200sf_fixed.tr','UlPdcpStats_100ue_200sf_fixed.tr']

print 'variable TTI Downlink' 
for tst in tstFileDlVar :
    print tst + ': ',
    files = tstFileDlVar[tst]
    tstDatDl[tst] = []
    for f in files:
        cmd = 'grep DlRxPDU data/' + f + ' | awk \'{ if($8 < 10000000) total += $8 } END { print total/NR }\''
        c = os.popen(cmd)
        res = float(c.read().rstrip())
        print str(res),
        tstDatDl[tst].append(res/1000000.0)
    print ''
       
print 'variable TTI Uplink' 
for tst in tstFileUlVar :
    print tst + ': ',
    files = tstFileUlVar[tst]
    tstDatUl[tst] = []
    for f in files:
        cmd = 'grep UlRxPDU data/' + f + ' | awk \'{ if($8 < 10000000) total += $8 } END { print total/NR }\''
        c = os.popen(cmd)
        res = float(c.read().rstrip())
        print str(res),
        tstDatUl[tst].append(res/1000000.0)
    print ''    
   
print 'fixed TTI Downlink' 
for tst in tstFileDlFixed :
    print tst + ': ',
    files = tstFileDlFixed[tst]
    tstDatDl[tst] = []
    for f in files:
        cmd = 'grep DlRxPDU data/' + f + ' | awk \'{ if($8 < 100000000) total += $8 } END { print total/NR }\''
        c = os.popen(cmd)
        res = float(c.read().rstrip())
        print str(res),
        tstDatDl[tst].append(res/1000000.0)
    print ''    
    
print 'fixed TTI Uplink' 
for tst in tstFileUlFixed :
    print tst + ': ',
    files = tstFileUlFixed[tst]
    tstDatUl[tst] = []    
    for f in files:
        cmd = 'grep UlRxPDU data/' + f + ' | awk \'{ if($8 < 100000000) total += $8 } END { print total/NR }\''
        c = os.popen(cmd)
        res = float(c.read().rstrip())
        print str(res),
        tstDatUl[tst].append(res/1000000.0)
    print ''      
    
numFlows = [10,20,50,100]

yticks = [0,1,5,10,25]
lineStyle = ['*-','.-','x-','d-','s-','o-']
tstListDl = ['fixed 50us sf','fixed 100us sf','fixed 200us sf','var 50us sf','var 200us sf','var 100us sf',]
istyle = 0
for tst in tstListDl:
    plt.semilogy(numFlows,tstDatDl[tst],lineStyle[istyle],label=tst)
    istyle = istyle + 1
plt.legend(bbox_to_anchor=(0.4, 1.1))
#plt.yticks(yticks)
plt.title('')
# pylab.text(0, 0, txJitterLabel, fontsize=12)
plt.xlabel("Num DL flows")
plt.ylabel("Mean PDCP latency (ms)")
plt.show()  

yticks = [0,0.5,1,5]
istyle = 0
tstListUl = ['fixed 50us sf','fixed 200us sf','fixed 100us sf','var 200us sf','var 100us sf','var 50us sf',] 
for tst in tstListUl:
    plt.semilogy(numFlows,tstDatUl[tst],lineStyle[istyle],label=tst)
    istyle = istyle + 1
plt.legend(bbox_to_anchor=(0.4, 1.1))
#plt.yticks(yticks)
plt.title('')
# pylab.text(0, 0, txJitterLabel, fontsize=12)
plt.xlabel("Num UL flows")
plt.ylabel("Mean PDCP latency (ms)")
plt.show()    
      
    

# class TraceDat:
#     def __init__(self,nlines):
#         self.frameNum = np.zeros(nlines) 
#         self.sfNum = np.zeros(nlines)
#         self.sinr = np.zeros(nlines) 
#         self.mcs = np.zeros(nlines)
#         self.rate = np.zeros(nlines) 
#         self.tbler = np.zeros(nlines)
#         self.corrupt = np.zeros(nlines)
#     frameNum = np.zeros(0)
#     sfNum = np.zeros(0)
#     sinr = np.zeros(0) 
#     mcs = np.zeros(0)
#     rate = np.zeros(0) 
#     tbler = np.zeros(0)
#     corrupt = np.zeros(0)
#     numAvgTerms = np.zeros(0) # number of terms per MCS used to compute rate
#     intervalMcs = np.zeros(0)
#     intervalRate = np.zeros(0)
#     intervalMcs = np.zeros(0)
#     intervalTbler = np.zeros(0)
# 
# class McsDat:
#     def __init__(self,mcs):
#         self.mcs = mcs
#     mcs = 0
#     sinr = np.zeros(0)
#     rate = np.zeros(0)
#     
# class AvgDat:
#     def __init__(self,mcs):
#         self.mcs = mcs
#     mcs = np.zeros(0)
#     sinrAvg = np.zeros(0)
#     rateAvg = np.zeros(0)
# 
# csvDir = '.'
# #csvFileList = ['UlRxTrace_AWGN_noharq.tr','UlRxTrace_fading_noharq.tr','UlRxTrace_fading_harq.tr']
# csvFileList = ['RxPacketTrace.txt']
# datList = [];
# lineSkip = 4;
# for file in csvFileList:
#     csvPath = csvDir + "/" + file
#     trace = 'UlRxTrace'
#     cmdWc = 'grep ' + trace + ' ' + csvPath + ' | wc -l'
#     c = os.popen(cmdWc)
#     numLines = int(c.read().rstrip())
#         
#     rateScale = float(8.0 / 100.0)  # Mbps per 100 microsecond subframe
#     dat = [ McsDat(i) for i in range(0,29) ]
#     lineIdx = 0
#     with open(csvPath, 'rb') as csvFile:
#         reader = csv.reader(csvFile, delimiter='\t')
#         try:
#             for row in reader:
#                 if(lineIdx > lineSkip and len(row) == 11 and row[0] == trace): 
#                     mcsIdx = int(row[6])
#                     sinr = round(10*math.log10(float(row[8])),3)
#                     tbSize = int(row[5])
#                     tbler = float(row[9])
#                     corrupt = int(row[10]) 
#                     dat[mcsIdx].sinr = np.append(dat[mcsIdx].sinr,sinr)
#                     dat[mcsIdx].rate = np.append(dat[mcsIdx].rate,tbSize*(1.0-corrupt)*rateScale)
#                 lineIdx += 1;
#         except csv.Error as e:
#             sys.exit('file %s, line %d: %s' % (csvPath, reader.line_num, e))
#     # end with
#     datList.append(dat)  
#    
# avgDatList = [ AvgDat(i) for i in range(0,len(csvFileList)) ]
# 
# nBuckets = 2
# for i in range(0,len(avgDatList)):
#     traceDat = datList[i]
#     for j in range(0,29):
#         mcsDat = traceDat[j]
#         mcsDat.sinr = np.sort(mcsDat.sinr)
#         if(len(mcsDat.sinr) > nBuckets):
#             nBucketElem = int(math.floor(len(mcsDat.sinr) / nBuckets))
#             for b in range(0,nBuckets):
#                 avgDatList[i].mcs = np.append(avgDatList[i].mcs,j)
#                 avgDatList[i].sinrAvg = np.append(avgDatList[i].sinrAvg,\
#                                                   np.mean(mcsDat.sinr[ b*nBucketElem:min((b+1)*nBucketElem,len(mcsDat.sinr)) ]))
#                 avgDatList[i].rateAvg = np.append(avgDatList[i].rateAvg,\
#                                                   np.mean(mcsDat.rate[ b*nBucketElem:min((b+1)*nBucketElem,len(mcsDat.rate)) ]))
# 
# labels = ['AWGN','fading','HARQ']
# 
# plotMcsSinr = True
# if plotMcsSinr:
#     for i in range(0,len(avgDatList)):
#         numEl = min(len(avgDatList[i].mcs),len(avgDatList[i].rateAvg))
#         plt.plot(avgDatList[i].mcs[0:numEl],avgDatList[i].rateAvg[0:numEl])
#     plt.legend(bbox_to_anchor=(0.5, 1))
#     plt.title('Rate vs. MCS')
#     # pylab.text(0, 0, txJitterLabel, fontsize=12)
#     plt.xlabel("MCS")
#     plt.ylabel("Rate (Mbps)")
#     plt.show()
# 
# plt.clf()
# plotSinrRate = True
# if plotSinrRate:
#     for i in range(0,len(avgDatList)):
#         numEl = min(len(avgDatList[i].sinrAvg),len(avgDatList[i].rateAvg))
#         plt.plot(avgDatList[i].sinrAvg[0:numEl],avgDatList[i].rateAvg[0:numEl])
#     plt.legend(bbox_to_anchor=(0.5, 1))
#     plt.title('SINR vs. Rate')
#     # pylab.text(0, 0, txJitterLabel, fontsize=12)
#     plt.xlabel("SINR (dB)")
#     plt.ylabel("Rate (Mbps)")
#     plt.show()

# pylab.plot(latency[0:(count-1)])
# pylab.title('UDP perf test (Boost): end-to-end latency')
# pylab.text(0, 0, latencyLabel, fontsize=12)
# pylab.xlabel("packet index")
# pylab.ylabel("latency (ms)")
# pylab.show()
# 
# bins = [.01, .05, .1, .5, 1.0, 10.0, 20.0]
# pylab.hist(latency[0:(count-1)], bins)
# pylab.title('UDP perf test (Boost): end-to-end latency histogram')
# pylab.ylabel("number of packets")
# pylab.xlabel("latency (ms)")
# pylab.show()

