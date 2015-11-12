#include <twodshape.h>

void  TwoDShape :: set_shape()
{
    while(true)
    {
        cout << "Enter x coordinate:";
        cin >> xCor;
        if(true == cin.good())
        {
            cin.ignore(100, '\n');
            break;
        }
        cin.clear();
        cin.ignore(100, '\n');
        cerr << "Wrong number, enter again" << endl;
    }
    while(true)
    {
        cout << "Enter y coordinate:";
        cin >> yCor;
        if(true == cin.good())
        {
            cin.ignore(100, '\n');
            break;
        }
        cin.clear();
        cin.ignore(100, '\n');
        cerr << "Wrong number, enter again" << endl;
    }
}

istream& operator>>(istream& stream, TwoDShape& shape)
{
    shape.set_shape();
    return stream;
}

ostream& operator<<(ostream& stream, TwoDShape& shape)
{
    shape.info();
    return stream;
}
