#ifndef DATE_H
#define DATE_H
#include <ctime>



class Date
{
    private:
        int month;
        int day;
        int year;
    public:
        void get_date();
        void show_date()const;
        bool is_correct();
        int current_year();
};
#endif // DATE_H
