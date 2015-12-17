#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

const int size = 50;

struct Data
{
    int id;
    int amount;
    float cost;
    char type[size];
    char name[size];

    Data(): id(0), amount(0), cost(0), type("\0"), name("\0")
    {}
    Data(int i, int a, float c, char* t, char* n): id(i), amount(a), cost(c)
    {
        if(strlen(t) < size && strlen(n) < size)
        {
            strcpy(type,t);
            strcpy(name,n);
        }
    }
};


class Data_file
{
    private:
        Data information;
        fstream* file;
        char* filename;
        int number_of_elements;
    public:
        Data_file():information(), file(NULL), filename(NULL), number_of_elements(0)
        {}
        Data_file(char* fname):information(), filename(fname)
        {
            file = new fstream();
            file->open(filename,ios::binary | ios::in | ios::out | ios::app);
            number_of_elements = num_calculate();
        }
        ~Data_file()
        {
            file->close();
        }
        int num_calculate();
        void get_data();
        void put_data() const;
        void write_data();
        void read_data();
        void delete_line();
        int search(int req_id);
        void show();
};

int Data_file :: num_calculate()
{
    file->seekg(0, ios :: end);
    int number = file->tellg()/sizeof(information);
    file->seekg(0, ios :: beg);
    return number;
}

void Data_file :: get_data()
{
    while(true)
    {
        cout << "Enter id:" << endl;
        cin >> information.id;

        if(true == cin.good() && information.id > 0)
        {
            cin.ignore(100, '\n');
            break;
        }
        cin.clear();
        cin.ignore(100, '\n');
        cerr << "You have entered wrong number, try again" << endl;
    }

    while(true)
    {
        cout << "Enter amount:" << endl;
        cin >> information.amount;

        if(true == cin.good() && information.amount > 0)
        {
            cin.ignore(100, '\n');
            break;
        }
        cin.clear();
        cin.ignore(100, '\n');
        cerr << "You have entered wrong number, try again" << endl;
    }
    while(true)
    {
        cout << "Enter cost:" << endl;
        cin >> information.cost;

        if(true == cin.good() && information.cost > 0)
        {
            cin.ignore(100, '\n');
            break;
        }
        cin.clear();
        cin.ignore(100, '\n');
        cerr << "You have entered wrong number, try again" << endl;
    }
    while(true)
    {
        cout << "Enter type of a product:" << endl;
        cin.getline(information.type, size);

        if(true == cin.good())
            break;
        cin.clear();
        cerr << "You have entered wrong type, try again" << endl;
    }
    while(true)
    {
        cout << "Enter product name:" << endl;
        cin.getline(information.name, size);

        if(true == cin.good())
            break;
        cin.clear();
        cerr << "You have entered wrong name, try again" << endl;
    }

}

void Data_file :: put_data() const
{
    cout.setf(ios :: left);
    cout << "id: " << information.id << '\t'
         << "amount :" << information.amount << '\t'
         << "cost: " << information.cost << '\t';
    cout << "type: " << information.type << '\t'
         << "name: " << information.name << endl;
}

void Data_file :: write_data()
{
    if(false == file->is_open())
    {
        cerr << "File error" << endl;
        exit(-1);
    }
    file->write(reinterpret_cast<char*>(&information), sizeof(information));
    number_of_elements++;
}

void Data_file :: read_data()
{
    if(false == file->is_open() || 0 == number_of_elements)
    {
        cerr << "File error" << endl;
        exit(-1);
    }
    file->read(reinterpret_cast<char*>(&information), sizeof(information));
}

void Data_file :: show()
{
    if(false == file->is_open())
    {
        cerr << "File error" << endl;
        exit(-1);
    }

    for(int i = 0; i < number_of_elements; i++)
    {
        this->read_data();
        this->put_data();
    }
}

int Data_file :: search(int req_id)
{
    if(false == file->is_open())
    {
        cerr << "File error" << endl;
        exit(-1);
    }

    file->seekg(0, ios :: beg);

    for(int i = 0; i < number_of_elements; i++)
    {
        this->read_data();
        if(this->information.id == req_id)
        {
            cout << "Element found in " << i << " position" << endl;
            return i;
        }
    }
    cerr << "Element wasn't found" << endl;
    return 0;
}

void Data_file :: delete_line()
{



}

int main()
{
    Data_file f("kek.txt");

    f.show();

    f.search(123);

    return 0;
}
