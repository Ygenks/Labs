#!/usr/bin/env python

import turtle
import sys

def draw_circle(args):
	

	arglist = sys.argv[1].split()
	x = int(arglist[0])
	y = int(arglist[1])
	radius = int(arglist[2])


	window = turtle.Screen()
	circle = turtle.Turtle()

	circle.hideturtle()

	circle.color("green")
	circle.begin_fill()
	
	circle.penup()
	circle.goto(x, y)
	circle.pendown()
	circle.circle(radius)

	circle.end_fill()
	window.exitonclick()


draw_circle(sys.argv[1])


