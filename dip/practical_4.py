import numpy as np
import cv2
import matplotlib.pyplot as plt
from skimage import data
from scipy.fftpack import fft2

img = cv2.imread("./bird.jpg", cv2.IMREAD_GRAYSCALE)
plt.imshow(img, cmap="gray")
plt.title("Original Image")
plt.show()

fourier_transform = fft2(img)
magnitude_spectrum = np.log(np.abs(fourier_transform))
plt.title("Fourier Transform (Magnitude Spectrum)")
plt.imshow(magnitude_spectrum, cmap="gray")
plt.show()


def downsample(image, factor):
    return image[::factor, ::factor]


downsampled_image = downsample(img, 2)
plt.title("Downsampled Image")
plt.imshow(downsampled_image, cmap="gray")
plt.show()

def quantize(image, levels):
    quantized_image = np.floor(image / (256 / levels)) * (256 / levels)
    return quantized_image.astype(np.uint8)


quantized_image = quantize(img, 16)
plt.title("Quantized Image")
plt.imshow(quantized_image, cmap="gray")
plt.show()


quantized_fourier = fft2(quantized_image)
quantized_magnitude_spectrum = np.log(np.abs(quantized_fourier))
plt.title("Fourier Transform of Quantized Image")
plt.imshow(quantized_magnitude_spectrum, cmap="gray")
plt.show()
