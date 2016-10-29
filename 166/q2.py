# -*- coding: utf-8 -*-
"""
Spyder Editor

This temporary script file is located here:
C:\Users\Yukitoshi\.spyder2\.temp.py
"""
#Image.open(I).convert('L') #grayscale
from PIL import Image

figure_4_42 = Image.open('4_42.tif').convert('L')
figure_4_42 = array(figure_4_42,dtype='float')

(width,height) = figure_4_42.shape

P = width*2
Q = height*2 

def D(u,v):
    return sqrt((u - P/2)**2 + (v - Q/2)**2)
    
def H(u,v,D0):
    if D(u,v) <= D0:
        return 1
    else:
        return 0
        
# 10, 30, 60, 160, 460

x_range = arange(0,P)
y_range = arange(0,Q)

H_filter_10 = array([[H(x,y,10) for x in x_range] for y in y_range])

PQ_image = zeros((P,Q))

PQ_image[0:width,0:height] = figure_4_42

figure_freq = fft2(PQ_image)

filtered_image = figure_freq*H_filter_10

filtered_image = fftshift(filtered_image)


filtered_in_spatial = ifft2(filtered_image)

cropped_final_image = filtered_in_spatial[0:width,0:height]
imshow(real(cropped_final_image),cmap='gray')
