# -*- coding: utf-8 -*-
"""
Created on Wed Oct 23 22:37:58 2013

@author: Yukitoshi
"""

from PIL import Image
import scipy.signal as signal

figure_4_41_a = Image.open('4_41_a.jpg').convert('L')
figure_4_41_a = array(figure_4_41_a,dtype='float')

figure_4_41_b = Image.open('4_41_b.jpg').convert('L')
figure_4_41_b = array(figure_4_41_b,dtype='float')

f_a = zeros((298,298))
f_b = zeros((298,298))

f_a[0:256,0:256] = figure_4_41_a
f_b[0:38,0:42] = figure_4_41_b

r_f_b = rot90(f_b)
r_f_b = rot90(r_f_b)

convolved = signal.fftconvolve(f_a,r_f_b)
imshow(convolved)

f_row = convolved[405]

