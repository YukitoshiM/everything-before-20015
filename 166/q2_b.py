# -*- coding: utf-8 -*-
"""
Created on Wed Oct 23 22:37:58 2013

@author: Yukitoshi
"""

from PIL import Image

figure_4_41_a = Image.open('4_41_a.jpg').convert('L')
figure_4_41_a = array(figure_4_41_a,dtype='float')


figure_4_41_b = Image.open('4_41_b.jpg').convert('L')
figure_4_41_b = array(figure_4_41_b,dtype='float')

f_a = zeros((298,298))
f_b = zeros((298,298))

f_a[0:256,0:256] = figure_4_41_a
f_b[0:38,0:42] = figure_4_41_b

F = fft2(f_a)
H = fft2(f_b)

"""
F_star = conj(F)

F_star_H = F_star*H

inverse_FH = ifft2(F_star_H)
"""

H_star = conj(H)

F_H_star = F*H_star

inverse_FH = ifft2(F_H_star)

f_row = inverse_FH[0:298,108]
