#include "employee.h"



void employee :: get_employee()
{
    while(true)
    {
        cout << "Enter id:" << endl;
        cin >> id;

        if(true == cin.good() && id >= 0)
        {
            cin.ignore(10, '\n');
            break;
        }
        cin.clear();
        cin.ignore(10, '\n');
        cerr << "Wrong id" << endl;
    }

    while(true)
    {
        cout << "Enter salary:" << endl;
        cin >> salary;

        if(true == cin.good() && salary > 0.0)
        {
            cin.ignore(10, '\n');
            break;
        }
        cin.clear();
        cin.ignore(10, '\n');
        cerr << "Wrong salary" << endl;
    }

    char post = '\0';

    while(true)
    {
        cout << "Enter post (l - laborer, s - secretary, m - manager):" << endl;
        cin >> post;


            switch(post)
            {
                case 'l':
                {
                    type = laborer;
                    break;
                }
                case 's':
                {
                    type = secretary;
                    break;
                }
                case 'm':
                {
                    type = manager;
                    break;
                }
                default :
                {
                    cerr << "You have entered wrong type" << endl;
                    cin.clear();
                    cin.ignore(10, '\n');
                    continue;
                }
            }
        cin.ignore(10, '\n');
        break;
    }
       date.get_date();
}

void employee :: put_employee()
{
    cout << "id: " << id << endl << "salary: " << salary << endl;
    date.show_date();
    cout << "type: ";
    switch(type)
    {
        case laborer:
        {
            cout << "laborer" << endl;
            break;
        }
        case secretary:
        {
            cout << "secretary" << endl;
            break;
        }
        case manager:
        {
            cout << "manager" << endl;
            break;
        }
    }
}
