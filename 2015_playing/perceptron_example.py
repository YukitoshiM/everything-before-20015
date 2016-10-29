# -*- coding: utf-8 -*-
"""
Created on Thu Jul 23 15:13:27 2015

@author: woolon
"""

import matplotlib.pyplot as plt

def perceptron(data_set):
    i = 0
    j = 15
    range_x = []
    x_0 = 1.0    
    w_0 = -7
    w_1 = 2
    p = 1.2/6
    checker = 1
    g = 0.0
    list_w_0 = [w_0]
    list_w_1 = [w_1]
    while i < 31:
        range_x.append(j)
        j -= 1
        i += 1

    for i in data_set:
        temp_list = []
        k = 0
        for j in range_x:
            k += 1
            temp_list.append(-i[0]*j)
            if i[1] == '+':
                plt.plot(range_x[0:k], temp_list, 'r')
            else:
                plt.plot(range_x[0:k], temp_list, 'b')
    
    while checker != 0:
        checker = 0
        for i in data_set:
            g = w_0 + i[0]*w_1
            if (i[1] == '+' and g < 0):
                w_0 = w_0 + p*x_0
                w_1 = w_1 + p*i[0]
                list_w_0.append(w_0)
                list_w_1.append(w_1)
                checker += 1
            elif (i[1] == '-' and g > 0):
                w_0 = w_0 - p*x_0
                w_1 = w_1 - p*i[0]
                list_w_0.append(w_0)
                list_w_1.append(w_1)
                checker += 1
    plt.plot(list_w_1, list_w_0, 'g')


data_set = [(1.2,'+'), (0.2,'+'), (-0.2,'+'), (-0.5,'-'), (-1.0,'-'), (-1.5,'-')]
perceptron(data_set)

plt.axis([-16,16,-25,25])
plt.show()
#



#plt.plot( [3,1,4,1,5,9,2,6,5] )
#plt.show()