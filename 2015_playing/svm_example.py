# -*- coding: utf-8 -*-
"""
Created on Mon Aug 03 14:20:53 2015

@author: woolon
"""
def maximize_lamda(data, a_i):
    total = -100 #since any result of this func. is negative take random large negative to start compare
    next_one = 0.0
    i = 0
    j = 0
    k = 0
    first = 0.0
    second = 0.0
    first = 0
    second = 0
    i = 0
    j = 0
    flag = 1
    checker = 0
    while k < 8:
        if flag == 1:
            a_i[k] += 1
        else:
            if a_i[k] > 0:
                a_i[k] -= 1
                checker = 1
            elif a_i[k] == 0:
                a_i[k] += 1
        while i < 8:
            first += a_i[i]
            while j < 8:
                second += a_i[i]*a_i[j]*data[i][2]*data[j][2]*(data[i][0]*data[j][0]+data[i][1]*data[j][1])
                j += 1
            j = 0
            i += 1
        next_one = first - second/2.0
        print 'k: '+ str(k)
        print 'total: '+ str(total)
        print 'new: '+ str(next_one)
        print a_i
        first = 0
        second = 0
        i = 0
        if next_one > total:
            total = next_one
            k = 0
        else:
            if flag == 1:
                a_i[k] -= 1
            else:
                if checker == 1:
                    a_i[k] += 1
                    checker = 0
                else:
                    a_i[k] -= 1
            k += 1
        if flag == 1 and k == 6:
            k = 0
            flag = 0
    return a_i

def find_w(a_i, data):
    w = [0, 0]
    i = 0
    while i < 8:
        if a_i[i] != 0:
            w[0] += a_i[i]*data[i][2]*data[i][0]
            w[1] += a_i[i]*data[i][2]*data[i][1]
        i += 1
    return w

def find_w_0(data, w, a_i):
    w_0 = [0, 0]
    i = 0
    while i < 8:
        if a_i[i] != 0:
            w_0[0] += -w[0]*data[i][0]/2.0
            w_0[1] += -w[1]*data[i][1]/2.0
        i += 1
    return w_0
    
    
data =[(1,2,1), (2,3,1), (1,4,1), (2,4,1), (2,1,-1), (3,2,-1), (5,1,-1), (4,2,-1)]
a_i = [0, 0, 0, 0, 0, 0, 0, 0]

a_i = maximize_lamda(data, a_i)
print a_i
a_i[1] = 1
a_i[5] = 1
w = find_w(a_i, data)
print w
print find_w_0(data, w, a_i)

        

