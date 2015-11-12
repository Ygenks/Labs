#ifndef TRIANGLE
#define TRIANGLE

#include "twodshape.h"

class Triangle : public TwoDShape
{
    private:
        int side; //xCor & yCor - coordinates of the top triangle apex
        const int height = side*sqrt(3)/2;
        string type = "triangle";
    public:
        Triangle(int x, int y, int s): TwoDShape(x, y), side(s)
        {}
        Triangle(): TwoDShape(), side(0)
        {}
        double area();
        void draw();
        void info();
        void set_shape();

};

#endif // TRIANGLE

