#include <tree.h>
int main()
{
    char option = '\0';
    while(true)
    {

        system("clear");

        Tree<char>* exp_tree;
        if('\0' == option)
            exp_tree = new Tree<char>;

        cout << "Choose option:\n"
                "1.Add expression\n"
                "2.Evaluate expression\n"
                "3.Clear tree\n"
                "4.Press q to exit" << endl;
        cin >> option;

        switch(option)
        {
            case '1':
            {
                char* expression = NULL;
                const int exp_size = 25;
                expression = new char[exp_size];

                system("clear");

                cout << "Input expression using the parantheses(like (4+(5*4)) )" << endl;
                cin >> expression;
                exp_tree->math_parse(expression);

                cin.ignore(100, '\n');

                break;
            }
            case '2':
            {
                system("clear");

                cout << "Result:" << exp_tree->evaluate() << endl << "Press ANIKEI to continue" << endl;
                cin.ignore(100, '\n');
                cin.get();

                break;
            }
            case '3':
            {
                if(true == exp_tree->is_empty())
                {
                    cerr << "Tree is empty" << endl;
                    break;
                }
                exp_tree->deconstruction();
                break;
            }
            case 'q':
                exit(0);
            default:
                continue;
        }
    }
    return 0;
}
