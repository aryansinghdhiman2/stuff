import cv2
import matplotlib.pyplot as plt

image = cv2.imread("./bird.jpg")
gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
plt.imshow(gray_image, cmap='gray')
plt.title('Original Image')
plt.show()

equalized_image = cv2.equalizeHist(gray_image)
plt.imshow(equalized_image, cmap='gray')
plt.title('Equalized Image')
plt.show()