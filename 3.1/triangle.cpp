#include <triangle.h>

void Triangle :: draw()
{
    if(0 == fork())
    {
        string path = "/usr/bin/python";
        string script = "/home/ygenks/programming/Python/" + type + ".py";
        string args;

        args = to_string(xCor) + " " + to_string(yCor) + " " + to_string(side);

        char* a[4];
        a[0] = const_cast<char *> (path.c_str());
        a[1] = const_cast<char *> (script.c_str());
        a[2] = const_cast<char *> (args.c_str());
        a[3] = NULL;
        execvp(a[0],const_cast<char **>(a));

    }
}

double Triangle :: area()
{
    return side*height/2;
}

void Triangle :: info()
{
    cout << "Figure type: " << type << endl;
    cout << "Side lenght: " << side << endl;
    TwoDShape :: info();
}

void Triangle :: set_shape()
{
    TwoDShape :: set_shape();
    while(true)
    {
        cout << "Enter length of the side:";
        cin >> side;
        if(true == cin.good() && side > 0)
        {
            cin.ignore(100, '\n');
            break;
        }
        cin.clear();
        cin.ignore(100, '\n');
        cerr << "Wrong number, enter again" << endl;
    }
}
