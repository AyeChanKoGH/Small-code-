"""
get screen and drawing shape with python turtle
#To draw line, press "l" key and click first end point and second end point
#To draw circle, press "c" key and click the center point and click the quarent point
#To draw Rectangle, press "r" key and click 1st end point and second end point
#To clean the screen, press "delete" key.
"""
from turtle import*
import turtle
import time
import math
x=0
y=0
clicked=False
#To get the position of on screen click
def on_click(x,y):
    global clicked
    global po
    po=[x,y]
    clicked=Turtle
#To wait user point
def wait():
    global clicked
    turtle.update()
    clicked=False
    while not clicked:
        turtle.update()
        time.sleep(.1)
    clicked=False
turtle.update()
#drawing turtle line
def line():
    turtle.onscreenclick(on_click)
    wait()
    pu()
    goto(po[0],po[1])
    Fpo=po
    pd()
    turtle.onscreenclick(on_click)
    wait()
    goto(po[0],po[1])
#drawing circle
def dCircle():
    turtle.onscreenclick(on_click)
    wait()
    pu()
    goto(po[0],po[1])
    Fpo=po
    pd()
    turtle.onscreenclick(on_click)
    wait()
    Spo=po
    radi=math.sqrt(((Spo[0]-Fpo[0])**2)+((Spo[1]-Fpo[1])**2) )
    pu()
    goto(Fpo[0],Fpo[1]-radi)
    pd()
    circle(radi)
#drawing rectangular shape
def rectangle():
    turtle.onscreenclick(on_click)
    wait()
    pu()
    goto(po[0],po[1])
    Fpo=po
    pd()
    turtle.onscreenclick(on_click)
    wait()
    Spo=po
    goto(Spo[0],Fpo[1])
    goto(Spo[0],Spo[1])
    goto(Fpo[0],Spo[1])
    goto(Fpo[0],Fpo[1])
#To clean the screen
def Sclear():
    clear()
listen()
onkey(dCircle,"c")
onkey(rectangle,"r")
onkey(line,"l")
onkey(Sclear,"Delete")
mainloop()
