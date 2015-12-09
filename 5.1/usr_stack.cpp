#include "usr_stack.h"

template <class T>
void usr_stack<T> :: interface()
{
    char option = '0';
        while(option != '\0')
        {

            system("clear");

            cout << "Choose option:\n"
                    "1.Show optional element\n"
                    "2.Show current element\n"
                    "3.Move iterator \n"
                    "4.Press q to exit" << endl;
            cin >> option;

            switch(option)
            {
                case '1':
                {
                    int index = 0, result = 0;

                    while(true)
                    {
                        cout << "Enter index:";
                        cin >> index;
                        if(true == cin.good())
                        {
                            cin.ignore(100, '\n');
                            break;
                        }
                        cin.clear();
                        cin.ignore(100, '\n');
                        cerr << "Wrong number, enter again" << endl;
                    }
                    result = (*this)[index];
                    if(INT_MIN != result)
                        cout << result << endl;
                    cout << "Press anykey to continue" << endl;
                    cin.get();
                    break;
                }
                case '2':
                {
                    system("clear");
                    if(INT_MIN != this->get_data())
                        cout << this->get_data() << endl;
                    cout << "Press anykey to continue" << endl;
                    cin.ignore(100, '\n');
                    cin.get();
                    break;
                }
                case '3':
                {
                   (*this)++;
                    break;
                }
                case 'q':
                {
                    option = '\0';
                    break;
                }
                default:
                    continue;
            }
        }
}

template <class T>
T usr_stack<T> :: operator[](int index)
{
    try
    {
        int i = index;
        int result = 0;
        node = head;
        while(0 != i)
        {
            if(NULL == node->next)
                throw null_pointer("operator[]");
            node = node->next;
            i--;
        }
        result = node->data;
        node = head;
        return result;
    }
    catch(usr_stack::null_pointer)
    {
        cerr << "Wrong index: " << index << endl;
        node = head;
        return INT_MIN;
    }
}
