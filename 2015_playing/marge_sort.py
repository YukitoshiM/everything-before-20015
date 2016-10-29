# -*- coding: utf-8 -*-
"""
Created on Tue May 19 23:12:31 2015

@author: woolon
"""

import math
import random
import time
import matplotlib.pyplot as plt
       
def merge(array):
    mid = len(array)
    if mid > 1:
        left = merge(array[:(mid/2)]) #First half of the array to recursive call
        right = merge(array[(mid/2):]) #Second half of the array to recursive call
        array = [] # Assign empty list for return for recreating sorted list
        while len(left) != 0 and len(right) != 0: # Both returned lists are not empty then loop until one become empty
            if left[0] < right[0]: # if the first element in left is smaller then pop it and append to array, else pop the first element in right and append it to array
                array.append(left.pop(0))
            else:
                array.append(right.pop(0))
        if len(left) != 0: # If one of the divided arrays still have elements, marge them to the end of array 
            array.extend(left)
        elif len(right) != 0:
            array.extend(right)
    return array       # Returning the modified stack

#print merge([])
#print merge([2])
#print merge([2,1,3,4])     
#print merge([2,1,3,4,6,5,8,7,9])
#print merge([9,8,7,6,5,4,3,2,1,3,5])

"""sumOfTime = 0
sumPltList = []
nlognList = []
list1 = []
# For creating array of size i up to 100000 
for i in range(3000):
    # Each array of size i is tested 100 times
    for j in range(100):
        # insert random integer of range 0 to 100000 in each index for i times 
        for k in range(i):
            list1.append(random.randint(0,100000))
        # Take the time before merge sort is called
        t0 = time.clock()
        merge(list1)
        # Take the time after merge sort called
        t1 = time.clock()
        # reset the list for testing to be empty then append i ellemnts in the next iteration
        list1 = []
        # adding up the time be taken from last merge sort
        sumOfTime += t1 - t0
    # take the average of the time be added up
    sumOfTime /= 100
    print "i is: " + str(i)
    # store the time in the list and multiplied 2000000 for viewing better graph
    sumPltList.append(sumOfTime*2000000)
    # calculate nlogn based on i and make a list of them, but log0 is not exist, then insert 0 when i = 0
    if i != 0:
        nlognList.append(i*math.log(i)/math.log(2))
    else:
        nlognList.append(0.0)
    # reset the time for next iteration which will change the range of the list
    sumOfTime = 0
# plotting merge sort and nlogn
plt.plot(sumPltList, "r-", label = "Merge_Sort")
plt.plot(nlognList, "g-", label = "O(nlogn)")
# print the labels at the top left of the graph(loc = 2 decides the location to be top left) 
plt.legend(loc=2)
# insert labels for x-axis and y axis
plt.xlabel('number of elements in a list')
plt.ylabel('time be taken')
plt.show()""" 
