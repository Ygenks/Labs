#ifndef USR_STACK_H
#define USR_STACK_H

#include<stack.h>

template <class T>
class usr_stack
{
    private:
        stack_node<T>* head;
        stack_node<T>* node;
    public:
        class null_pointer
        {
            public:
                null_pointer(const char* function)
                {
                    cerr << "Iterator NULL pointer: " << function << endl;
                }
        };
        class empty_stack
        {
            public:
                empty_stack(const char* function)
                {
                    cerr << "Stack is empty:" << function << endl;
                }
        };

        usr_stack():head(NULL), node(NULL)
        {}
        usr_stack(Stack<T>& s):head(s.head), node(s.head)
        {}
        usr_stack(usr_stack& iter)
        {
            head = iter.head;
            node->data = iter.node->data;
            node->next = iter.node->next;
        }
        T operator[](int index);
        usr_stack& operator++()
        {
            node = node->next;
            return *this;
        }
        usr_stack& operator++(int)
        {
            if(NULL == node->next)
            {
                cerr << "NULL pointer" << endl;
                node = head;
            }
            node = node->next;
            return *this;
        }
        int& operator*()
        {
            return node->data;
        }
        int& operator->()
        {
            return node->data;
        }
        bool operator==(int& value)
        {
            return node->data == value;
        }
        bool operator==(usr_stack* i)
        {
            return node == i->node;
        }
        bool operator!=(usr_stack* i)
        {
            return node != i->node;
        }
        bool operator!=(int& value)
        {
            return node->data != value;
        }
        usr_stack& operator=(usr_stack& i)
        {
            head = i.head;
            node->data = i.node->data;
            node->next = i.node->next;
            return *this;
        }
        usr_stack& operator=(Stack<T>& st)
        {
            new (this) usr_stack(st);
            return *this;
        }
        usr_stack& operator=(int& i)
        {
            node->data = i;
            return *this;
        }
        bool is_null()
        {
            return NULL == node? true : false;
        }
        int get_data()
        {
            return node->data;
        }
        void interface();
};

#include "usr_stack.cpp"

#endif // USR_STACK_H
