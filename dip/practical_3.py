import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.imread("./bird.jpg", cv2.IMREAD_GRAYSCALE)
plt.imshow(img, cmap="gray")
plt.title("Original Image")
plt.show()


# def negativeTransform(image: cv2.Mat) -> cv2.typing.MatLike:
#     L = 256
#     neg = L - 1 - image
#     return neg


# neg = negativeTransform(img)
# plt.imshow(neg, cmap="gray")
# plt.title("Negative Image")
# plt.show()


# def logTransform(image: cv2.Mat, c: int) -> cv2.typing.MatLike:
#     logImg = c * np.log1p(image)
#     logImg = np.uint8(logImg / logImg.max() * 255)
#     return logImg


# logImg = logTransform(img,30)
# plt.imshow(logImg, cmap="gray")
# plt.title("Log Transformed Image")
# plt.show()

# def powerLawTransform(image:cv2.Mat,gamma : float) -> cv2.typing.MatLike:
#     gammaImg = np.power(img / float(np.max(image)),gamma)
#     return np.uint8(gammaImg * 255)

# gammaImg = powerLawTransform(img,2)
# plt.imshow(gammaImg, cmap="gray")
# plt.title("Power Law Transformed Image")
# plt.show()

# def peicewise_linear_transform(value,r1,s1,r2,s2):
#     if(value <= r1):
#         return (s1/r1) * value
#     elif(value<=r2):
#         return ((s2-s1) / (r2-r1)) * (value - r1) + s1
#     else:
#         return ((255 - s2) / (255 - r2)) * (value - r2) + s2

# def contrastStreching(image :cv2.Mat, r1,s1,r2,s2) -> cv2.typing.MatLike:
#     strechImg = np.vectorize(peicewise_linear_transform)(image,r1,s1,r2,s2)
#     return np.uint8(strechImg)

# contrastImg = contrastStreching(img,70,0,140,255)
# plt.imshow(contrastImg, cmap="gray")
# plt.title("Contrast Streched Image")
# plt.show()

# def averageBlur(image: cv2.Mat,kernel_size : int) -> cv2.typing.MatLike:
#     return cv2.blur(image,(kernel_size,kernel_size))

# blurImg = averageBlur(img,11)
# plt.imshow(blurImg,cmap='gray')
# plt.title('Averaging Filter')
# plt.show()

# def gaussianBlur(image :cv2.Mat,kernel_size,sigma) -> cv2.typing.MatLike:
#     return cv2.GaussianBlur(image,(kernel_size,kernel_size),sigma)

# gaussianImg = gaussianBlur(img,11,1)
# plt.imshow(gaussianImg,cmap="gray")
# plt.title("Guassian Blur")
# plt.show()

# def medianFilter(image:cv2.typing.MatLike,kernel_size:int) -> cv2.typing.MatLike:
#     return cv2.medianBlur(image,kernel_size)

# medianImg = medianFilter(img,11)
# plt.imshow(medianImg,cmap="gray")
# plt.title("Median Filter")
# plt.show()

# def laplacianSharpen(image : cv2.typing.MatLike) -> cv2.typing.MatLike:
#     return np.uint8(np.absolute(cv2.Laplacian(image,cv2.CV_64F))) 

# laplacianImg = laplacianSharpen(img)
# plt.imshow(laplacianImg,cmap="gray")
# plt.title("Laplacian Sharpening")
# plt.show()

def sobelSharpening(image:cv2.typing.MatLike) -> cv2.typing.MatLike:
    sobelx = cv2.Sobel(image,cv2.CV_64F,1,0,ksize=3)
    sobely = cv2.Sobel(image,cv2.CV_64F,0,1,ksize=3)

    sobel_combined = np.sqrt(sobelx**2 + sobely**2)
    sobel_combined = np.uint8(np.absolute(sobel_combined))
    return sobel_combined

sobelImg = sobelSharpening(img)
plt.imshow(sobelImg,cmap='gray')
plt.title('Sobel Sharpening')
plt.show()