# -*- coding: utf-8 -*-
"""
Created on Thu Apr 23 16:43:15 2015

@author: woolon
"""

class Queue:
    def __init__(self, queue = None):
        if type(queue) is type([]):
            self.queue = queue
        elif queue is None:
            self.queue = []
        else:
            print ('\nError Message:\n\tYour input is ' +
                    'not type of list!\n\tPlease enter list type!\n')
        
    def enqueue(self, e):
        self.queue.append(e)   #Appending new elements in the stack
        return self.queue      #Return the modified queue
        
    def dequeue(self):
        try:
            qEl = self.queue[0]         # Getting the first element in the queue
            del self.queue[0]           # Delete the element in index 0
            return (qEl, self.queue)    # Return the turple of (deleted element, modified queue)
        except IndexError:              # When IndexError ocurs, print out the message
            print '\nError Message:\n\tThere is no element in the queue!\n'
            
q = Queue([])
print q.enqueue(1)
print q.enqueue(2)
print q.dequeue()
print q.dequeue()
print q.dequeue()

q1 = Queue([])
print q1.enqueue('a')
print q1.enqueue('b')

q2 = Queue([])
print q2.enqueue('c')

print q1.dequeue()

q3 = Queue([])
q4 = Queue([])

print q3.enqueue(123)
print q4.dequeue()

q5 = Queue(2)

'''a = Queue()
b = Queue()
a.enqueue(123)
print b.dequeue()'''

