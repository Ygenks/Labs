#!/usr/bin/env python

import turtle
import sys

def draw_square(args):


	arglist = sys.argv[1].split()
	x = int(arglist[0])
	y = int(arglist[1])
	side = int(arglist[2])

	window = turtle.Screen()
	square = turtle.Turtle()

	square.hideturtle()

	square.color("blue")
	square.begin_fill()

	square.penup()
	square.goto(x, y)
	square.pendown()
	i = 4
	while i > 0:
		square.forward(side)
		square.right(90)
		i -= 1

	square.end_fill()	
	window.exitonclick()

draw_square(sys.argv[1])
