#include <iostream>

using namespace std;

struct stack_node
{
    int data;
    stack_node* next;

    stack_node(): data(0), next(NULL)
    {}
    stack_node(int value): data(value), next(NULL)
    {}
};

class usr_iterator
{

};

class iterator
{
    private:
        stack_node* node;
    public:
        iterator(): node(NULL)
        {}
        iterator(Stack& s): node(s.head)
        {}
        iterator(iterator& i)
        {
            *this = i;
        }
        void operator++(int KKK)
        {
            node = node->next;
        }
        int operator*()
        {
            return node->data;
        }
        int operator->()
        {
            return node->data;
        }
        bool operator==(int& value)
        {
            return node->data == value;
        }
        bool operator!=(int& value)
        {
            return node->data != value;
        }
        iterator& operator=(iterator& i)
        {
            node->data = i.data;
            node->next = i.next;
            return *this;
        }
        iterator& operator=(int& i)
        {
            node->data = i;
            return *this;
        }

};

class Stack
{
    private:
        stack_node* head;
    public:
        void pop();
        void push(int value);
        Stack* search(int key);

};
