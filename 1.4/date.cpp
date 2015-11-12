#include "date.h"

#include<iostream>

int Date :: current_year()
{
    time_t sec = time(NULL);
    tm* t = localtime(&sec);
    return t->tm_year + 1900;
}

bool Date :: is_correct()
{
    if(day < 0 || day > 31)
        return false;
    if(month < 1 || month > 12 )
        return false;
    if(year < 0  || year > current_year())
        return false;
    return true;
}

void Date :: show_date()const
{
    cout << "date:" << day << '.' << month << '.' << year << endl;
}

void Date :: get_date()
{
    char rubbish;
    while(false == is_correct())
    {
        cout << "Please Enter the Date(dd.mm.yyyy)" << endl;
        cin >> day >> rubbish >> month >> rubbish >> year;

        if(true == cin.good() && true == is_correct())
        {

            break;
        }

        cin.clear();
        cin.ignore(10 ,'\n');
        cerr << "You have entered wrong date" << endl;

    }
}

