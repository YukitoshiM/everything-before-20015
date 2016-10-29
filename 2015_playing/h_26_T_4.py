# -*- coding: utf-8 -*-
"""
Created on Sun Jul 19 12:06:34 2015

@author: woolon
"""

def int_match(text, pattern):
    i = 0
    j = 0
    while i < len(text):
        if text[i] == pattern[j]:
            j = j + 1
            i = i + 1
            if j == 4:
                return i - j
        else:
            if pattern[0] == text[i]:
                j = 0
            else:
                j = 0
                i = i +1
    return -1
    
text = [1,2,1,2,1,2,3,4]
pattern = [1,2,3,4]

print int_match(text, pattern)