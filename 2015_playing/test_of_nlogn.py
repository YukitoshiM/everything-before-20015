# -*- coding: utf-8 -*-
"""
Created on Wed May 27 11:55:14 2015

@author: woolon
"""

import math
import matplotlib.pyplot as plt

lognList = []
nList = []
nlognList = []
nSquareList = []

# For creating array of size i up to 100000 
for i in range(100):
    if i != 0:
        nList.append(2**math.log(i))
        nlognList.append(i*math.log(i)/math.log(2))
    else:
        nList.append(0.0)
        nlognList.append(0.0)

plt.plot(nList, "b-", label = "O(2^logn)")
plt.plot(nlognList, "g-", label = "O(nlogn)")

plt.legend(loc=2)
plt.xlabel('number of elements in a list')
plt.ylabel('time be taken')
plt.show()