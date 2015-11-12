#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>

enum etype{laborer, secretary, manager};

class employee
{
    private:
        int id;
        float salary;
        Date date;
        etype type;
    public:
        void get_employee();
        void put_employee();
};

#endif // EMPLOYEE_H
