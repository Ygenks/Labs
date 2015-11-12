#ifndef SQUARE
#define SQUARE

#include "twodshape.h"

class Square : public TwoDShape
{
    private:
        int side; //xCor & yCor - coordinates of the upper left corner
        string type = "square";
    public:
        Square(int x, int y, int s): TwoDShape(x, y), side(s)
        {}
        Square(): TwoDShape(), side(0)
        {}
        double area();
        void draw();
        void info();
        void set_shape();
};

#endif // SQUARE

