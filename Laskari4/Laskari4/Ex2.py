#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Wed Mar  1 02:17:12 2017

@author: sofiev
"""

print "Exercise 2"
import numpy
import matplotlib.pyplot as plt


import random
random.seed(431); # initializing MT.

distrData=numpy.loadtxt('distr1.dat')

iArraySize= sum(distrData[:,1])

aRandTable=numpy.zeros(int(iArraySize))  # synthetic datatable.
# idea to generate random value from 0 to iArraySize, and take a cell from table corresponding to it.

iIndex=0;
aKoko=distrData.shape ;
for i in range(aKoko[0]):
    aRandTable[iIndex:iIndex+int(distrData[i,1])]=int(distrData[i,0]);
    iIndex=iIndex + int(distrData[i,1])

# Table of distribution created, now time to simulate synthetic data

iMaxRuns=1;
aRunResults=numpy.zeros(iMaxRuns);

for iRun in range(iMaxRuns):
    #iRandLoc=random.randint(0, iArraySize);
    #iRandNum=aRandTable[iRandLoc];
    aResult=numpy.zeros(100);
    for i in range(100):
        iRandLoc=random.randint(0, iArraySize-1);
        iRandNum=aRandTable[iRandLoc];
        aResult[i]=iRandNum;

    if(iRun<5):        
        plt.figure();
        plt.hist(aResult);
        plt.ylabel("Counts")
        plt.xlabel("Value")
        plt.show()
    
    #CDF
    aHist, aBins= numpy.histogram(aResult, len(aResult))
    aCDF=numpy.cumsum(aHist);
    plt.figure;
    plt.plot(aBins[0:len(aCDF)], aCDF);
    plt.title("CDF")
    plt.ylabel("% of all")
    plt.show()
    
    print numpy.where(aCDF>84)[0][0]
    print aBins[numpy.where(aCDF>84)[0][0]]
    
#    aRunResults[iRun]=sum(aResult);
#    
#plt.figure;
#plt.hist(aRunResults);
#plt.title('Area')
#plt.show()
#
#aHist, aBins = numpy.histogram(aRunResults);
#aCDF = numpy.cumsum(aHist);
#
#plt.figure;
#plt.plot( aBins[0:len(aCDF)], aCDF);
#plt.title('CDF ')
#plt.show()
#

