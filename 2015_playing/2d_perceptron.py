# -*- coding: utf-8 -*-
"""
Created on Thu Jul 23 17:34:45 2015

@author: woolon
"""

import matplotlib.pyplot as plt

def perceptron(data_set):
    c = 1.0    
    a = 1.0
    b = 1.0
    p = 1.0
    checker = 1
    f = 0.0
    list_a = [a]
    list_b = [b]
    x_list = [0.1, 0.2, 0.3, 0.4]
    y_list = []
    k = 0
    color_list = ['b', 'r', 'c', 'm', 'y','--b', '--r', '--c', '--m', '--y']
    color_num = 0
    for i in x_list:
        k += 1
        y_list.append(c/b-a*i/(b))
        plt.plot(x_list[0:k], y_list, 'g', label = 'original')
    y_list = []
    while checker != 0:
        checker = 0
        for x in data_set:
            f = a*x[0] + b*x[1] - c
            if (x[2] == '+' and f < 0):
                a = a + p*x[0]
                b = b + p*x[1]
                c = c - p
                list_a.append(a)
                list_b.append(b)
                print (a,b,c)
                k = 0
                for i in x_list:
                    k += 1
                    y_list.append(c/b-a*i/(b))
                    plt.plot(x_list[0:k], y_list, color_list[color_num])
                color_num += 1
                checker += 1                
                y_list = []
            elif (x[2] == '-' and f >= 0):
                a = a - p*x[0]
                b = b - p*x[1]
                c = c + p
                list_a.append(a)
                list_b.append(b)
                print (a,b,c)
                k = 0
                for i in x_list:
                    k += 1
                    y_list.append(c/b-a*i/(b))
                    plt.plot(x_list[0:k], y_list, color_list[color_num])
                color_num += 1
                checker += 1
                y_list = []

data_set = [(0.3, 0.5, '+'), (0.25, 0.5, '-'), (0.25, 0.70, '+'), (0.3, 0.3,'-')]
perceptron(data_set)
for x in data_set:
    if x[2] == '+':
        plt.plot(x[0], x[1] , 'ro')
    else:
        plt.plot(x[0], x[1] , 'bo')
        
plt.axis([0.2,0.35,0.0,1.0])

plt.show()