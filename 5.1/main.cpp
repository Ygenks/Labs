#include<stack.h>

int main()
{
    try
    {
        Stack<double> s;

        for(int i = 0; i < 10; i++)
            s.push(i);

        usr_stack<double> it(s);
        it.interface();

        stack_iterator<double> iter(s);

        for(; !iter.is_null(); iter++)
            cout << iter.get_data() << endl;

        cout << "Geomerty mean:" <<s.g_mean() << endl;
        cout << "Maximum:" <<s.maximum() << endl;
        cout << "Minimum:" <<s.minimum() << endl;
        cout << "Median:" <<s.median() << endl;

        s.replace(3, 4);

        s.show();

        stack_node<double>* exep = s.search(5);
        cout << exep->data << endl;

        Stack<double> s1;
        s1.pop();
    }
    catch(Stack<double>::Empty)
    {}
    catch(Stack<double>::No_elem)
    {}
    return 0;
}

