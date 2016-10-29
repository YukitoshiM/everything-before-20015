from PIL import Image
import scipy.ndimage as ndimage

D = 11
test_img = zeros((D,D))
coords = [(0,0),(0,D-1),(D/2,D/2),(D-1,0),(D-1,D-1)]

for i in range(0,5):
    test_img[coords[i][0]][coords[i][1]] = 1

phi_range = range(-90,90)
A = zeros((2*sqrt(2)*D,180))

def houghTransform(x,y,phi):
    rad = pi*phi/180
    return x*cos(rad)+y*sin(rad)

for i in range(0,5):
    for phi in phi_range:
        p = houghTransform(coords[i][0],coords[i][1],phi)
        rp = int(p)
        A[p+sqrt(2)*D,90+phi] = A[p+sqrt(2)*D,90+phi] + 1
        
B = (A > 2)
B = B.astype('int')

listOfLines = []
x_range = range(0,11)

(h,w) = B.shape
for i in range(0,h):
    for j in range(0,w):
        if(B[i][j]):
            #p = i, phi = j
            p = i-h/2
            phi = pi*(j-w/2)/180
            slope = -(cos(phi)/sin(phi))
            intercept = p/sin(phi)
            y = [slope*x + intercept for x in x_range]
            listOfLines.append(y)

imshow(test_img,cmap='gray', interpolation='none')
for k in range(0,len(listOfLines)):
    plot(x_range,listOfLines[k])
    
xlim(-0.5,10.5)
ylim(-0.5,10.5)

I = Image.open('8_2a.jpg')
Iresize = I.resize((int(I.size[0]/2), int(I.size[1]/2)), Image.BILINEAR)

sx = ndimage.sobel(I, axis=0, mode='constant')
sy = ndimage.sobel(I, axis=1, mode='constant')
sob = hypot(sx, sy)

pic = 
