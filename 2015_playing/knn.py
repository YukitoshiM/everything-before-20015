# -*- coding: utf-8 -*-
"""
Created on Thu Jul 23 11:23:40 2015

@author: woolon
"""
"""
KNNを簡単に実装してみた。
１．　a_pointとdata_setの各々の要素のマンハッタン距離を求めて、その値とクラスのタプルを
　　　diff_data_setへ格納していく。
２．　すべてのマンハッタン距離とクラスの格納が終わったらリストをマンハッタン距離についてソー
　　　トする。
３．　最後にリストの頭３っつのクラスの多数決をとってクラス分けをする。
"""
import math
from operator import itemgetter

def knn(a_point, data_set):
    i = 0
    w_counter = 0
    b_counter = 0
    x_1 = a_point[0]
    y_1 = a_point[1]
    diff_data_set = []
    x_2 = data_set[0][0]
    #各々の点についてマンハッタン距離の計算
    for data_i in data_set:
        x_2 = data_i[0]
        y_2 = data_i[1]
        data_type = data_i[2]
        diff = math.fabs(x_1 - x_2) + math.fabs(y_1 - y_2)
        diff_data_set.append((diff, data_type))
    #マンハッタン距離のソート
    diff_data_set = sorted(diff_data_set, key=itemgetter(0))
    #頭３っつの多数決をとる
    while i < 3:
        if diff_data_set[i][1] == 'w':
            w_counter += 1
        else:
            b_counter += 1
        i += 1
    #結果表示
    if w_counter > b_counter:
        return 'a_point is classified to white'
    else:
        return 'a_point is classified to black'
       
data_set = [(-5,2,'w'),
            (-2,4,'w'),
            (-2,-1,'w'),
            (-1,3,'w'),
            (-5,-5,'b'),
            (3,-5,'b'),
            (4,-1,'b'),
            (4,1,'b'),
            (4,5,'b')]

a_point = (3,4)

print knn(a_point, data_set)