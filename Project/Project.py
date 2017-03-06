#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Sun Mar  5 15:05:03 2017

@author: sofiev
"""

# Project
# simulating sand pile with toppling.
import time
tStartTime=time.time()


import numpy
import random
import matplotlib.pyplot as plt

random.seed(431); # initializing Mersenne twister generator for result reproducibility

# Lets start with 1D case.

print "1D case"

# Creating array of 2000 to iinitialize the dimensions
iLength=500;


aiAll=numpy.zeros(iLength);

# Assuming sands are dropping only in region of 900-1100

iRange=5*pow(10,4);
iStamp=10;
iMaxTests=15;
aResult=numpy.zeros([iLength, int(iRange/iStamp)])
aTopplingResult=numpy.zeros([iMaxTests+1, int(iRange/iStamp)])
iResultIndex=0;

for iTest in range(iMaxTests):
    print iTest
    iResultIndex=0;
    aiAll=numpy.zeros(iLength);

    iToppling=0;
    #aTopplingResult=numpy.zeros([iMaxTests+1, int(iRange/iStamp)])
    for iSand in range(iRange):
        iPosition=int(random.random()*(0.1*iLength+1))+int(0.45*iLength); #range 900-1100.
        aiAll[iPosition]+=1;
        
        for iRunPos in range(iLength-2):
            if (aiAll[iRunPos+1] -aiAll[iRunPos] >2): # toppling left
                aiAll[iRunPos]+=1;
                aiAll[iRunPos+1]-=1;
                iToppling+=1;
            
            if (aiAll[iRunPos+1] -aiAll[iRunPos+2] >2): # toppling right
                aiAll[iRunPos+2]+=1;
                aiAll[iRunPos+1]-=1;
                iToppling+=1;
        
        # Setting endpoint values to be 0.
        aiAll[0]=0;
        aiAll[-1]=0;
        
        # Saving the situation at some moments
        if (iSand%iStamp==0):
            aResult[:, iResultIndex]=aiAll;
            aTopplingResult[0, iResultIndex]=iSand;
            aTopplingResult[iTest+1, iResultIndex]=iToppling;
            iResultIndex+=1;
            
            
    plt.imshow(aResult)
            


#plt.figure()
#for i in range(iMaxTests):
#    plt.plot(aTopplingResult[i,:], '-')
#
#plt.show()

plt.figure()
for i in range(iMaxTests):
    plt.plot(numpy.log(aTopplingResult[i+1,:]), aTopplingResult[0,:], '-')

plt.show()

#%% Plotting the situation over time:
plt.figure();
plt.imshow(aResult)
plt.ylabel('Index of cell in 1D')
plt.xlabel('Number of sand particles came into the system')
plt.show()

#%% Plotting the number of toppled particles

plt.figure()
plt.xlabel('Number of sand particles came into the system')
plt.ylabel('Number of toppled particles')

for i in range(iMaxTests):
    plt.plot( aTopplingResult[0,:], aTopplingResult[i+1,:], '-')

plt.show()



#%% Part 2, going for s_alpha rule.
#Here it is thought that all sand drops immidiately and then sorting out how many topples.
#Lets assume that 1/3 of piled up above the lower one drops to the lower one.

iSize=1000;
aResultPart2=numpy.zeros(iSize);
aSums=[]
aNs=[]

for N in range(3,11):
    iMaxSands=pow(5,N);
    aNs.append(iMaxSands)
    
    # Generating the sand falling...
    for iSand in range(iMaxSands):
        aResultPart2[int((iSize-2)*random.random()) +1]+=1; # generating values to all except the edge cells.
    
    plt.figure()
    plt.title('Starting situation')
    plt.ylabel('Height')
    plt.xlabel('Index in 1D array')
    plt.plot(aResultPart2, '*')
    plt.show()
    aTopplingValues=[];
    
    iIndex=0;
    while(iIndex<iSize-2):
        iIndex+=1;
        
        #if going to topple
        # if unsure direction:
        if(aResultPart2[iIndex]-aResultPart2[iIndex-1]>2 and aResultPart2[iIndex]-aResultPart2[iIndex+1]>2):
            #if left is lower going there
            if(aResultPart2[iIndex-1]<=aResultPart2[iIndex+1]):
                dTemp=(aResultPart2[iIndex]-aResultPart2[iIndex-1])/3;
                aResultPart2[iIndex-1]+=int(dTemp);
                aResultPart2[iIndex]-=int(dTemp);
                aTopplingValues.append(int(dTemp));
                iIndex=0;
            # else going right
            else:
                dTemp=(aResultPart2[iIndex]-aResultPart2[iIndex+1])/3;
                aResultPart2[iIndex+1]+=int(dTemp);
                aResultPart2[iIndex]-=int(dTemp);
                aTopplingValues.append(int(dTemp));
                iIndex=0;
        #if only left lower
        elif (aResultPart2[iIndex]-aResultPart2[iIndex-1]>2):
            dTemp=(aResultPart2[iIndex]-aResultPart2[iIndex-1])/3;
            aResultPart2[iIndex-1]+=int(dTemp);
            aResultPart2[iIndex]-=int(dTemp);        
            aTopplingValues.append(int(dTemp));            
            iIndex=0;
        #if only right one
        elif (aResultPart2[iIndex]-aResultPart2[iIndex+1]>2):
            dTemp=(aResultPart2[iIndex]-aResultPart2[iIndex+1])/3;
            aResultPart2[iIndex+1]+=int(dTemp);
            aResultPart2[iIndex]-=int(dTemp);        
            aTopplingValues.append(int(dTemp));            
            iIndex=0;

    aSums.append(sum(aTopplingValues))

#%% Plotting the histogram
plt.figure()
plt.hist(aTopplingValues)

#%%
plt.figure()
plt.title('End situation')
plt.ylabel('Height')
plt.xlabel('Index in 1D array')
plt.plot(aResultPart2, '*')
plt.show()


tEndTime=time.time()   

print "Run time: ", tEndTime-tStartTime 