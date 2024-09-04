import cv2

image = cv2.imread("./bird.jpg")
print(image)
cv2.imshow("image",image)
cv2.waitKey(0)