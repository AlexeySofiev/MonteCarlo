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

iMaxRuns=5;
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
        plt.savefig('data/ex2_synt'+str(iRun)+'.png')
    
    #CDF
    aHist, aBins= numpy.histogram(aResult, len(aResult))
    aCDF=numpy.cumsum(aHist);
    plt.figure();
    plt.plot(aBins[0:len(aCDF)], aCDF);
    plt.title("CDF")
    plt.ylabel("% of all")
    #plt.show()

    #print "Lower edge"
    #print numpy.where(aCDF>=16)[0][0]
    #print aBins[numpy.where(aCDF>=16)[0][0]]
    dLowerLoc=numpy.where(aCDF>=16)[0][0];
    dLowerEdge=aBins[numpy.where(aCDF>=16)[0][0]];


    #print "Central point"
    #print numpy.where(aCDF>=50)[0][0]
    #print aBins[numpy.where(aCDF>=50)[0][0]]
    dMidPoint=aBins[numpy.where(aCDF>=50)[0][0]];
    dMidLoc=numpy.where(aCDF>=50)[0][0];

    #print "Upper edge"    
    #print numpy.where(aCDF>=84)[0][0]
    #print aBins[numpy.where(aCDF>=84)[0][0]]
    dUpperEdge=aBins[numpy.where(aCDF>=84)[0][0]];
    dUpperLoc=numpy.where(aCDF>=84)[0][0]
    
    print dMidPoint,"(+", dUpperEdge-dMidPoint,", - ", dLowerEdge, ")"
    
    #aEdges=numpy.array([dLowerEdge, dLowerLoc], [dMidPoint, dMidLoc], [dUpperEdge, dUpperLoc]);
            
    #plt.plot(aEdges, 'r*')
    plt.plot(dLowerEdge,aCDF[dLowerLoc],'r*')
    plt.plot(dUpperEdge,aCDF[dUpperLoc],'r*')
    plt.plot(dMidPoint,aCDF[dMidLoc],'r*')
    
    plt.savefig("data/ex2_cdf.png")
    

    
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



########## --------------------------------------------------##################3
## POISSON ##
##########-------------------------------------------------- ###################

for iRun in range(iMaxRuns):
    #iRandLoc=random.randint(0, iArraySize);
    #iRandNum=aRandTable[iRandLoc];
    aResult=numpy.zeros(100);
    for i in range(100):
        aResult[i]=numpy.random.poisson(3);

    if(iRun<5):        
        plt.figure();
        plt.hist(aResult);
        plt.ylabel("Counts")
        plt.xlabel("Value")
        plt.savefig('data/ex2_poisson_synt'+str(iRun)+'.png')
    
    #CDF
    aHist, aBins= numpy.histogram(aResult, len(aResult))
    aCDF=numpy.cumsum(aHist);
    plt.figure();
    plt.plot(aBins[0:len(aCDF)], aCDF);
    plt.title("Poisson CDF")
    plt.ylabel("% of all")
    #plt.show()

    #print "Lower edge"
    #print numpy.where(aCDF>=16)[0][0]
    #print aBins[numpy.where(aCDF>=16)[0][0]]
    dLowerLoc=numpy.where(aCDF>=16)[0][0];
    dLowerEdge=aBins[numpy.where(aCDF>=16)[0][0]];


    #print "Central point"
    #print numpy.where(aCDF>=50)[0][0]
    #print aBins[numpy.where(aCDF>=50)[0][0]]
    dMidPoint=aBins[numpy.where(aCDF>=50)[0][0]];
    dMidLoc=numpy.where(aCDF>=50)[0][0];

    #print "Upper edge"    
    #print numpy.where(aCDF>=84)[0][0]
    #print aBins[numpy.where(aCDF>=84)[0][0]]
    dUpperEdge=aBins[numpy.where(aCDF>=84)[0][0]];
    dUpperLoc=numpy.where(aCDF>=84)[0][0]
    
    print dMidPoint,"(+", dUpperEdge-dMidPoint,", - ", dLowerEdge, ")"
    
    #aEdges=numpy.array([dLowerEdge, dLowerLoc], [dMidPoint, dMidLoc], [dUpperEdge, dUpperLoc]);
            
    #plt.plot(aEdges, 'r*')
    plt.plot(dLowerEdge,aCDF[dLowerLoc],'r*')
    plt.plot(dUpperEdge,aCDF[dUpperLoc],'r*')
    plt.plot(dMidPoint,aCDF[dMidLoc],'r*')
    
    plt.savefig("data/ex2_poisson_cdf.png")
    





