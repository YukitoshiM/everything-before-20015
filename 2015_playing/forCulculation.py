# -*- coding: utf-8 -*-
"""
Created on Thu Jun 18 14:38:32 2015

@author: woolon
"""
import math

sum = 0
sumAll = 0
"""
for i in range(8):
    for j in range(i,56,8):
        sum += (0.98**j * 0.02)
    sum += (0.98**56)/8
    print 'p(' + str(i)+'): ' + str(sum)
    sumAll += sum
    sum = 0
print sumAll
"""
"""
j = 0
for i in range(0,56,1):
    sum += (0.98**j * 0.02) * (i + 1)
    print sum
sum = sum + 56*(0.98**56)
"""
"""
#エントロピー簡単計算式
x = 0.675
y = 1- x
print -x*math.log(x,2)-y*math.log(y,2)
"""

"""
#情報理論 5.4
listOfY = [0.747, 0.166, 0.081, 0.018, 0.018, 0.144, 0.072, 0.016, 0.016, 0.128, 0.066, 0.528]
sum = 0
for x in listOfY:
    sum += -x*math.log(x,2)
print sum/6
"""


print -0.5*math.log(0.5,2)























