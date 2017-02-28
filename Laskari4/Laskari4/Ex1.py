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


#plt.hist(ex1data,200)

plt.hist(ex1data[ex1data<5], 50)

plt.show()

