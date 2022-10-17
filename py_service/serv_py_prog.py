import pygame
pygame.joystick.init()
joysticks= [pygame.joystick.Joystick(0)]
pygame.init()

while True:
    for event in pygame.event.get():
        if event.type== pygame.QUIT:
            break
        if event.type== pygame.JOYAXISMOTION:
            print(event)



