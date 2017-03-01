#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Sat Feb 25 11:57:56 2017

@author: sofiev
"""

import os
os.chdir('/home/sofiev/University/Kurssit/MonteCarlo/Laskari4/Laskari4')

import numpy
ex1data=numpy.loadtxt('data/ex1.txt')

import matplotlib.pyplot as plt


plt.hist(ex1data,200)

#plt.hist(ex1data[ex1data>0], 50)


plt.show()



#%%

ex1logData=numpy.loadtxt('data/ex1_E_R.txt');

logE=numpy.log(ex1logData[:,1]);
logR=numpy.log(ex1logData[:,2]);

plt.figure()
plt.plot(logR,logE,'*-')
plt.xlabel("log(R)")
plt.ylabel("log(E)")


plt.show()
