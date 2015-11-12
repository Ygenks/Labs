#ifndef CIRCLE
#define CIRCLE

#include "twodshape.h"

class Circle : public TwoDShape
{
    private:
        int radius; //xCor & yCor - coordinates of the center of the square
        string type = "circle";
    public:
        Circle(int x, int y, int r): TwoDShape(x, y), radius(r)
        {}
        Circle(): TwoDShape(), radius(0)
        {}
        double area();
        void draw();
        void info();
        void set_shape();
};

#endif // CIRCLE

