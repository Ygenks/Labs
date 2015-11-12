#include <circle.h>

double Circle :: area()
{
    return M_PI*radius*radius;
}

void Circle :: info()
{
    cout << "Figure type: " << type << endl;
    cout << "Radius lenght: " << radius << endl;
    TwoDShape :: info();
}

void Circle :: draw()
{
        if(0 == fork())
        {
            string path = "/usr/bin/python";
            string script = "/home/ygenks/programming/Python/" + type + ".py";
            string args;

            args = to_string(xCor) + " " + to_string(yCor) + " " + to_string(radius);

            char* a[4];
            a[0] = const_cast<char *> (path.c_str());
            a[1] = const_cast<char *> (script.c_str());
            a[2] = const_cast<char *> (args.c_str());
            a[3] = NULL;
            execvp(a[0],const_cast<char **>(a));
        }
}

void Circle :: set_shape()
{
    TwoDShape :: set_shape();
    while(true)
    {
        cout << "Enter length of the radius:";
        cin >> radius;
        if(true == cin.good() && radius > 0)
        {
            cin.ignore(100, '\n');
            break;
        }
        cin.clear();
        cin.ignore(100, '\n');
        cerr << "Wrong number, enter again" << endl;
    }
}
