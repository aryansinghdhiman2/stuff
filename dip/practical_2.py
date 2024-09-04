import cv2
import numpy as np

image = cv2.imread("./bird.jpg")

gray = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)

height, width = gray.shape

pseudo_colored = np.zeros((height, width, 3), dtype=np.uint8)

for i in range(0,height):
    for j in range(0,width):
        if(gray[i][j] < 85):
            pseudo_colored[i][j][2] = gray[i][j]
        elif(gray[i][j] >= 85 and gray[i][j]< 170):
            pseudo_colored[i][j][1] = gray[i][j]
        else:
            pseudo_colored[i][j][0] = gray[i][j]

pseudo_colored_2 = cv2.applyColorMap(gray,cv2.COLORMAP_OCEAN)

cv2.imshow("Manual Pseudo Colored",pseudo_colored)
cv2.imshow("Automatic Pseudo Coloring",pseudo_colored_2)
cv2.imshow("Original Image",image)
cv2.imshow("Monochrome Image",gray)

cv2.waitKey(0)
