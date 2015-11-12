#include <circle.h>
#include <square.h>
#include <triangle.h>
#include <vector>
/**/

/*
class ThreeDShape : protected Shape
{
    protected:
        int zCor;
    public:
        ThreeDShape(int x, int y, int z): Shape::Shape(x, y), zCor(z)
        {}
        ThreeDShape(): Shape(), zCor(0)
        {}
        virtual double volume() = 0;
        void info()
        {
            Shape :: info();
            cout << "Z coordinate: " << zCor << endl;
            cout << "Volume: " << this->volume() << endl;
        }
};

class Cube : public ThreeDShape
{
    private:
        int edge;
    public:
        Cube(int x, int y, int z, int s): ThreeDShape(x, y, z), edge(s)
        {}
        Cube(): ThreeDShape(), edge(0)
        {}
        void draw();
        double volume();
        void info();
};

class Sphere : public ThreeDShape
{
    private:
        int radius;
    public:
        Sphere(int x, int y, int z, int r): ThreeDShape(x, y, z), radius(r)
        {}
        Sphere(): ThreeDShape(), radius(0)
        {}
        void draw();
        double volume();
        void info();
};

double Cube :: volume()
{
    return edge*edge*edge;
}

void Cube :: info()
{
    cout << "Figure type: cube" << endl;
    cout << "Edge lenght: " << edge << endl;
    ThreeDShape :: info();
}

double Sphere :: volume()
{
    return (4/3)*M_PI*(radius*radius*radius);
}

void Sphere :: info()
{
    cout << "Figure type: sphere" << endl;
    cout << "Radius lenght: " << radius << endl;
    ThreeDShape :: info();
}

*/

int main()
{

    vector <TwoDShape*> figure;

    char answer;

    while(answer != 0)
    {
        cin >> answer;

        switch(answer)
        {
            case 't':
            {
                figure.push_back(new Triangle);
                break;
            }

            case 's':
            {
                figure.push_back(new Square);
                break;
            }
            case 'c':
            {
                figure.push_back(new Circle);
                break;
            }
            default:
            {
              answer = 0;
              break;
            }

        }
    }

    /*const int number = 3;

    TwoDShape* figure[number];

    figure[0] = new Square();
    figure[1] = new Circle();
    figure[2] = new Triangle();

    for(int i = 0; i < number; i++)
        cin >> *figure[i];

    for(int i = 0; i < number; i++)
    {
        figure[i]->draw();
        cout << *figure[i];
    }
*/
    for(int i = 0; i < figure.size(); i++)
        figure.push_back();

    return 0;
}
