import csv
import numpy as np
import pylab
import matplotlib.pyplot as plt
import os
import math
from scipy.interpolate import interp1d

np.set_printoptions(threshold=np.nan)

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

def movingAvg(interval, window_size):
    window= numpy.ones(int(window_size))/float(window_size)
    return numpy.convolve(interval, window, 'same')

class McsDat:
    def __init__(self,mcs,numLines):
        self.mcs = mcs
        self.sinr = np.zeros(numLines)
        self.rate = np.zeros(numLines)
        self.tbler = np.zeros(numLines)
    mcs = 0
    sinr = np.zeros(0)
    rate = np.zeros(0)
    tbler = np.zeros(0)
    
class AvgDat:
    def __init__(self,mcs):
        self.mcs = mcs
    mcs = np.zeros(0)
    sinrAvg = np.zeros(0)
    rateAvg = np.zeros(0)
    tblerAvg = np.zeros(0)

csvDir = '..'
#csvFileList = ['UlRxTrace_AWGN_noharq.tr','UlRxTrace_fading_noharq.tr','UlRxTrace_fading_harq.tr']
# csvFileList = ['fading_noharq_mcs0.tr','awgn_noharq_mcs0.tr','fading_noharq_mcs5.tr','awgn_noharq_mcs5.tr',\
#                 'fading_noharq_mcs10.tr','awgn_noharq_mcs10.tr','fading_noharq_mcs15.tr','awgn_noharq_mcs15.tr',\
#                 'fading_noharq_mcs20.tr','awgn_noharq_mcs20.tr','fading_noharq_mcs28.tr','awgn_noharq_mcs28.tr']
#csvFileList = ['awgn_noharq_all.tr','fading_noharq_all.tr','fading_harq_all.tr']
csvFileList = ['RxPacketTrace.txt']
datList = [];
lineSkip = -1;
rateScale = float(8.0 / 100.0)  # Mbps per 100 microsecond subframe
maxSinr = -100;
for file in csvFileList:
    csvPath = csvDir + "/" + file
    trace = 'UlRxTrace'
    cmdWc = 'grep ' + trace + ' ' + csvPath + ' | wc -l'
    c = os.popen(cmdWc)
    numLines = int(c.read().rstrip())
        
    dat = [ McsDat(i,numLines) for i in range(0,29) ]
    lineIdx = 0
    with open(csvPath, 'rb') as csvFile:
        reader = csv.reader(csvFile, delimiter='\t')
        try:
            for row in reader:
                if(lineIdx > lineSkip and len(row) == 13 and row[0] == trace): 
                    #mcsIdx = int(row[7])
                    mcsIdx = 0
                    if (lineIdx < len(dat[mcsIdx].sinr)):
                        tbSize = int(row[6])
                        sinr = round(10*math.log10(float(row[9])),3)
                        #sinr = float(row[9])
                        tbler = float(row[10])
                        corrupt = int(row[11]) 
                        dat[mcsIdx].sinr[lineIdx] = sinr
                        if (sinr > maxSinr):
                            maxSinr = sinr
                        dat[mcsIdx].rate[lineIdx] = tbSize*(1.0-corrupt)*rateScale
                        dat[mcsIdx].tbler[lineIdx] = tbler
                        #dat[mcsIdx].rate[lineIdx] = tbSize*(1.0-tbler)*rateScale
                lineIdx += 1;
        except csv.Error as e:
            sys.exit('file %s, line %d: %s' % (csvPath, reader.line_num, e))
    # end with
    datList.append(dat)  
   
avgDatList = [ AvgDat(i) for i in range(0,len(csvFileList)) ]

nBuckets = 0
nBucketElem = 63000
for i in range(0,len(avgDatList)):
    traceDat = datList[i]
    for j in range(0,29):
        mcsDat = traceDat[j]
        if (sum(mcsDat.sinr) > 0 and len(mcsDat.sinr)> nBucketElem):
            #nBuckets = len(mcsDat.rate)/100
            #mcsDat.sinr = np.sort(mcsDat.sinr)
            sortIdx = np.argsort(mcsDat.sinr)
            #mcsDat.sinr = mcsDat.sinr[sortIdx]
            #mcsDat.rate = mcsDat.rate[sortIdx]
            nBuckets = int(math.ceil((len(mcsDat.rate)/nBucketElem)))
            if(1 and len(mcsDat.sinr) > nBuckets):
                nBucketElem = int(math.floor(len(mcsDat.rate) / nBuckets))
                for b in range(0,nBuckets):
                    avgDatList[i].mcs = np.append(avgDatList[i].mcs,j)
                    avgDatList[i].sinrAvg = np.append(avgDatList[i].sinrAvg,\
                                                      np.mean(mcsDat.sinr[ b*nBucketElem:min((b+1)*nBucketElem,len(mcsDat.sinr)) ]))
                    avgDatList[i].rateAvg = np.append(avgDatList[i].rateAvg,\
                                                      np.mean(mcsDat.rate[ b*nBucketElem:min((b+1)*nBucketElem,len(mcsDat.rate)) ]))
              
            
            #sortIdx = np.argsort(avgDatList[i].sinrAvg)
            #avgDatList[i].sinrAvg = avgDatList[i].sinrAvg[sortIdx]
            #avgDatList[i].rateAvg = avgDatList[i].rateAvg[sortIdx]
            #avgDatList[i].sinrAvg = np.convolve(mcsDat.sinr, np.ones(nBuckets)/nBuckets, 'valid')
            #avgDatList[i].rateAvg = np.convolve(mcsDat.rate, np.ones(nBuckets)/nBuckets, 'valid')
            
# for i in range(0,len(avgDatList)):
#     traceDat = datList[i]
#     for j in range(0,29):
#         mcsDat = traceDat[j]
#         #sort_index = np.argsort(avgDatList[i].sinrAvg)
#         #avgDatList[i].sinrAvg = avgDatList[i].sinrAvg[sort_index]     
#         #avgDatList[i].rateAvg = avgDatList[i].rateAvg[sort_index] 
#         if ((i % 2 == 1) and i < len(avgDatList)-2):
#             avgDatList[i+2].rateAvg = avgDatList[i+2].rateAvg[avgDatList[i+2].rateAvg > avgDatList[i].rateAvg.max()]
#             avgDatList[i+1].rateAvg = avgDatList[i+1].rateAvg[avgDatList[i+1].rateAvg > avgDatList[i].rateAvg.max()]
#             avgDatList[i+2].sinrAvg = avgDatList[i+2].sinrAvg[avgDatList[i+2].rateAvg > avgDatList[i].rateAvg.max()]
#             avgDatList[i+1].sinrAvg = avgDatList[i+1].sinrAvg[avgDatList[i+1].rateAvg > avgDatList[i].rateAvg.max()]
#             #avgDatList[i].sinrAvg = np.append(avgDatList[i].sinrAvg,avgDatList[i+2].sinrAvg.min())
#             #avgDatList[i].rateAvg = np.append(avgDatList[i].rateAvg,avgDatList[i].rateAvg.max())

# sinrFading = []
# rateFading = []
# sinrAwgn = []
# rateAwgn = []
# 
# for i in range(0,len(avgDatList)):
#     traceDat = datList[i]
#     for j in range(0,29):
#         mcsDat = traceDat[j]
#         if ((i % 2 == 0) and i < len(avgDatList)-1 and len(avgDatList[i].rateAvg) > 0):
#            sinrFading = np.append(sinrFading,avgDatList[i].sinrAvg)
#            rateFading = np.append(rateFading,avgDatList[i].rateAvg)
#            sinrAwgn = np.append(sinrAwgn,avgDatList[i+1].sinrAvg)
#            rateAwgn = np.append(rateAwgn,avgDatList[i+1].rateAvg)
#            break

labels = ['AWGN w/o HARQ','AWGN w/ HARQ','fading w/ HARQ']

plotMcsSinr = False
if plotMcsSinr:
    for i in range(0,len(avgDatList)):
        numEl = min(len(avgDatList[i].mcs),len(avgDatList[i].rateAvg))
        plt.plot(avgDatList[i].mcs[0:numEl],avgDatList[i].rateAvg[0:numEl])
    plt.legend(bbox_to_anchor=(0.5, 1))
    plt.title('Rate vs. MCS')
    # pylab.text(0, 0, txJitterLabel, fontsize=12)
    plt.xlabel("MCS")
    plt.ylabel("Rate (Mbps)")
    plt.show()

traceDat = datList[0]
mcsDat = traceDat[0]

plt.clf()
plt.plot(mcsDat.sinr, label=labels[0])
plt.show()

plt.clf()

plotSinrRate = True
if plotSinrRate:
    for i in range(0,len(avgDatList)):
        if (len(avgDatList[i].sinrAvg) == 0):
            continue
        numEl = min(len(avgDatList[i].sinrAvg),len(avgDatList[i].rateAvg))  
#         sort_index = np.argsort(avgDatList[i].sinrAvg)
#         avgDatList[i].sinrAvg = avgDatList[i].sinrAvg[sort_index]
#         avgDatList[i].rateAvg = avgDatList[i].rateAvg[sort_index]
        #numEl = np.argmax(avgDatList[i].sinrAvg)
        #print avgDatList[i].sinrAvg
        #print ""
        #print avgDatList[i].rateAvg
        plt.plot(avgDatList[i].sinrAvg[0:numEl], avgDatList[i].rateAvg[0:numEl], label=labels[i])
    #numEl = min(len(sinrAwgn),len(rateAwgn))
    #print sinrAwgn[0:numEl]
    #print ""
    #print rateAwgn[0:numEl]
    #plt.plot(sinrAwgn[0:numEl], rateAwgn[0:numEl])
    #plt.plot(sinrFading[0:numEl], rateFading[0:numEl])
    plt.legend(bbox_to_anchor=(0.5, 1))
    plt.title('Rate vs. SINR')
    # pylab.text(0, 0, txJitterLabel, fontsize=12)
    plt.xlabel("SINR (dB)")
    plt.ylabel("Rate (Mbps)")
    plt.show()

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

