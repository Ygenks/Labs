#!/usr/bin/env python

import turtle
import sys

def draw_triangle(args):

	arglist = sys.argv[1].split()
	x = int(arglist[0])
	y = int(arglist[1])
	side = int(arglist[2])

	window = turtle.Screen()
	triangle = turtle.Turtle()

	triangle.hideturtle()

	triangle.color("red")
	

	triangle.penup()
	triangle.goto(x, y)
	triangle.pendown()

	triangle.right(60)

	triangle.begin_fill()

	i = 2
	while i > 0:
		triangle.forward(side)
		triangle.right(120)
		i -= 1

	triangle.end_fill()
	window.exitonclick()



draw_triangle(sys.argv[1])