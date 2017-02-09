#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Thu Feb  9 01:02:59 2017

@author: sofiev
"""
import numpy
a=numpy.loadtxt('data/ex4inv.txt')
len1=len(a);


import matplotlib.pyplot as plt
import numpy as np

a=a[a<10];
a=a[a>-10];

plt.figure(1)
plt.hist(a,30)
plt.title("Histogram of random numbers from the function by inversion")
plt.xlabel("Binned random values")
plt.ylabel("Count")

plt.savefig('ex4histInv.png')
#fig = plt.gcf()

print 'This % of values went outside [-10, 10] region.'
print 1.0*(len1-len(a))/len1
          
          
          
#%%
## Combined part

combHit=numpy.loadtxt('data/ex4combHist.txt')
combMiss=numpy.loadtxt('data/ex4combHistMiss.txt')

#%%
#plt.figure(2);
#plt.plot(combHit[:,0],combHit[:,1],'*')
#plt.plot(combMiss[:,0],combMiss[:,1],'r*')

plt.figure(2)
plt.hist(combHit[:,0],30)
plt.savefig('ex4histComb.png')

plt.show()
#plt.savefig('ex4histComb.png')

