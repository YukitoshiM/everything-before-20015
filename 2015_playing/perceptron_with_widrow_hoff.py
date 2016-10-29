# -*- coding: utf-8 -*-
"""
Created on Sat Jul 25 11:13:09 2015

@author: woolon
"""

#import matplotlib.pyplot as plt
    
def widrow_hoff(data_set):
    x_0 = 1.0    
    w_0 = 0.2
    w_1 = 0.3
    p = 0.2
    b = (1,0)
    e_for_w_0_list = []
    e_for_w_1_list = []
    time = 0
    while time < 11:
        for i in data_set:
            if i[1] == '+':
                e_for_w_0_list.append(w_0*x_0 +w_1*i[0] - b[0])
                e_for_w_1_list.append((w_0*x_0 +w_1*i[0] - b[0])*i[0])
            else:
                e_for_w_0_list.append(w_0*x_0 +w_1*i[0] - b[1])
                e_for_w_1_list.append((w_0*x_0 +w_1*i[0] - b[1])*i[0])
        w_0 -= p*sum(e_for_w_0_list)
        w_1 -= p*sum(e_for_w_1_list)
        e_for_w_0_list = []
        e_for_w_1_list = []
        time += 1
    print (w_0,w_1)
    
        


data_set = [(1.0,'+'), (0.5,'+'), (-0.2,'-'), (-0.4,'+'), (-1.3,'-'), (-2.0,'-')]
#perceptron(data_set)
widrow_hoff(data_set)

#plt.axis([-1.5,1.5,-1.5,1.5])
#plt.show()