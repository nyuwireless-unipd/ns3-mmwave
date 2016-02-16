import csv
import numpy as np
import pylab
import matplotlib.pyplot as plt
import os
import math

tstFileDlVar = {}
tstFileUlVar = {}
tstFileDlFixed = {}
tstFileUlFixed = {}

tstDatDl = {} #defaultdict(list)
tstDatUl = {} #defaultdict(list)

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
        cmd = 'grep DlRxPDU data_old/' + f + ' | awk \'{ if($8 < 10000000) total += $8 } END { print total/NR }\''
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
        cmd = 'grep UlRxPDU data_old/' + f + ' | awk \'{ if($8 < 10000000) total += $8 } END { print total/NR }\''
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
        cmd = 'grep DlRxPDU data_old/' + f + ' | awk \'{ if($8 < 100000000) total += $8 } END { print total/NR }\''
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
        cmd = 'grep UlRxPDU data_old/' + f + ' | awk \'{ if($8 < 100000000) total += $8 } END { print total/NR }\''
        c = os.popen(cmd)
        res = float(c.read().rstrip())
        print str(res),
        tstDatUl[tst].append(res/1000000.0)
    print ''      
    
numFlows = [10,20,50,100]

lineStyle = ['*-','.-','x-','d-','s-','o-']

# yticks = [0,1,5,10,25]
# tstListDl = ['fixed 50us sf','fixed 100us sf','fixed 200us sf','var 50us sf','var 200us sf','var 100us sf',]
# istyle = 0
# fig = plt.figure()
# ax = fig.add_subplot(111)
# for tst in tstListDl:
#     ax.semilogy(numFlows,tstDatDl[tst],lineStyle[istyle],label=tst)
#     istyle = istyle + 1
# #ax.legend(bbox_to_anchor=(0.4, 1.1))
# ax.annotate('local max', xy=(0.2, 1), xytext=(0.2, 1),
#             arrowprops=dict(facecolor='black', shrink=0.05),
#             )
# #plt.yticks(yticks)
# plt.title('')
# # pylab.text(0, 0, txJitterLabel, fontsize=12)
# plt.xlabel("Num DL flows")
# plt.ylabel("Mean PDCP latency (ms)")
# plt.show()  

yticks = [0,0.5,1,5]
istyle = 0
tstListUl = ['fixed 50us sf','fixed 200us sf','fixed 100us sf','var 200us sf','var 100us sf','var 50us sf',] 
fig2 = plt.figure()
ax2 = fig2.add_subplot(111)
# ax2.annotate('6x improvement', xy=(85,2), xytext=(85, 2),)
# ax2.annotate('', xy=(100, tstDatUl['fixed 100us sf'][-1]), xycoords='data', xytext=(100, tstDatUl['var 100us sf'][-1]),
#             arrowprops=dict(facecolor='black',arrowstyle='<->',connectionstyle='bar,fraction=-0.2'),
#             )
for tst in tstListUl:
    ax2.semilogy(numFlows,tstDatUl[tst],lineStyle[istyle],label=tst,linewidth=2.0,markersize=10.0)
    istyle = istyle + 1
ax2.legend(bbox_to_anchor=(0.4, 1.1))
ax2.set_xlabel('Num UL flows',fontsize=14)
ax2.set_ylabel('Mean PDCP latency (ms)',fontsize=14)
#plt.yticks(yticks)
#plt.title('')
# pylab.text(0, 0, txJitterLabel, fontsize=12)
#plt.xlabel("Num UL flows")
#plt.ylabel("Mean PDCP latency (ms)")
plt.show()    
      
    