#ifndef SHAPE
#define SHAPE

#include <iostream>
#include <math.h>
#include <unistd.h>
#include <string>
#include <stdio.h>
using namespace std;

class Shape
{
    protected:
        int xCor;
        int yCor;
    public:
        Shape(int x, int y): xCor(x), yCor(y)
        {}
        Shape(): xCor(0), yCor(0)
        {}
        virtual void draw() = 0;
        virtual void info() = 0;
};

#endif // SHAPE

