# -*- coding: utf-8 -*-
"""
Created on Thu Apr 23 13:29:13 2015

@author: woolon
"""

class Stack:
    def __init__(self, stack = None):
        if type(stack) is type([]):
            self.stack = stack
        elif stack is None:
            self.stack = []
        else:
            print ('\nError Message:\n\tYour input is ' +
                    'not type of list!\n\tPlease enter list type!\n')
        
    def push(self, e):
        self.stack.append(e)    # Appending the new elements in the stack
        return self.stack       # Returning the modified stack
        
    def pop(self):
        try:
            sEl = self.stack.pop()    # Getting the last element, and delete from the stack
            return (sEl, self.stack)  # Returning the turple of (the element, mofified stack)
        except IndexError:            # When IndexError ocurs, printing the message
            print '\nError Message:\n\tThere is no element in the stack!\n'

"""s = Stack([])
print s.push(1)
print s.push(2)
print s.pop()
print s.pop()
print s.pop()"""

a = Stack(2)
b = Stack([])
#print a.push(123)
print b.pop()