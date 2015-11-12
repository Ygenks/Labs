#ifndef TWODSHAPE
#define TWODSHAPE

#include "shape.h"

class TwoDShape : protected Shape
{
    public:
        TwoDShape(int x, int y): Shape(x,y)
        {}
        TwoDShape(): Shape :: Shape()
        {}
        virtual double area() = 0;
        void info()
        {
            Shape :: info();
            cout << "Area: " << this->area() << endl;
        }
        virtual void set_shape() = 0;
        virtual void draw() = 0;
        friend istream& operator>>(istream& stream, TwoDShape& shape);
        friend ostream& operator<<(ostream& stream, TwoDShape& shape);
};

#endif // TWODSHAPE

