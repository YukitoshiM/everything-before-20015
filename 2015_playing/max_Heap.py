# -*- coding: utf-8 -*-
"""
Created on Sat Jul 18 14:14:57 2015

@author: woolon
"""

def parent(i):
    return i/2
    
def left(i):
    return i*2 + 1
    
def right(i):
    return i*2 + 2

largest = 0
temp = 0
    
def max_heapify(array, i):
    l = left(i)
    r = right(i)
    if l <= len(array)-1 and array[l] > array[i]:
        largest = l
    else:
        largest = i
    if r <= len(array)-1 and array[r] > array[largest]:
        largest = r
    if largest != i:
        temp = array[i]
        array[i] = array[largest]
        array[largest] = temp
        max_heapify(array,largest)

def build_max_heap(array):
    i = len(array)/2 
    while i != -1:
        max_heapify(array, i)
        print array
        i -= 1
        
def heap_sort(array):
    sorted_array = []
    build_max_heap(array)
    i = len(array) - 1
    while i != -1:
        sorted_array.insert(0,array[0])
        temp = array[i]
        array[i] = array[0]
        array[0] = temp
        del array[i]
        if len(array) > 1:
            build_max_heap(array)
        i -= 1
    return sorted_array
    
array1 = [34,70,13,55,21,89,41]

build_max_heap(array1)
print array1