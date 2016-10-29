# -*- coding: utf-8 -*-
"""
Created on Mon Dec 02 23:47:17 2013

@author: Yukitoshi
"""

I = Image.open('8_2a.jpg')
imgData = array(I,dtype='uint')
#Iresize = I.resize((int(I.size[0]/2), int(I.size[1]/2)), Image.BILINEAR)

phi_range = range(-90,90)

def houghTransform(x,y,phi):
    rad = pi*phi/180
    return x*cos(rad)+y*sin(rad)

(H,W) = size(I)
p_max = round(sqrt(H**2+W**2))

A_H = int(2*p_max)
A_W = 180
A = zeros((A_H,A_W))

for i in range(0,H):
    for j in range(0,W):
        if(imgData[i][j]>0):
            for phi in phi_range:
                p = houghTransform(i,j,phi)
                rp = int(p)
                A[rp+p_max,90+phi] = A[rp+p_max,90+phi] + 1

# find threshold
max_acc = 0
for i in range(0,A_H):
    for j in range(0,A_W):
        if A[i,j] > max_acc:
            max_acc = A[i,j]
            

tau = 0.8*max_acc

B = (A > tau)
B = B.astype('int')

listOfLines = []
x_range = range(0,H)

(h,w) = B.shape
for i in range(0,h):
    for j in range(0,w):
        if(B[i][j]>0):
            #p = i, phi = j
            p = i-h/2
            phi = pi*(j-w/2)/180
            slope = -(cos(phi)/sin(phi))
            intercept = p/sin(phi)
            y = [slope*x + intercept for x in x_range]
            listOfLines.append(y)

imshow(I,cmap='gray', interpolation='none')
for k in range(0,len(listOfLines)):
    plot(x_range,listOfLines[k])
    

xlim(0,H)
ylim(W,0)

