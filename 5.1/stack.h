#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

using namespace std;

template <class T>
struct stack_node
{
    T data;
    stack_node* next;
    stack_node(): data(0), next(NULL)
    {}
    stack_node(T& value): data(value), next(NULL)
    {}
};

template <class T> class usr_stack;
template <class T> class stack_iterator;

template <class T>
class Stack
{
    private:
        stack_node<T>* head;
    public:
        friend class stack_iterator<T>;
        friend class usr_stack<T>;
        class Empty
        {
            public:
                Empty(const char* function)
                {
                    cerr << "Stack is empty: " << function << endl;
                }
        };
        class No_elem
        {
            public:
                No_elem(const char* function)
                {
                    cerr << "NULL element pointer: " << function << endl;
                }
        };

        Stack(): head()
        {}
        T pop();
        void push(T value);
        void show();
        stack_node<T>* search(T key);
        void replace(T rep_to, T rep_by);
        T median();
        T maximum();
        T minimum();
        T g_mean();
        bool is_empty()
        {
            return head == NULL? true : false;
        }
};

#include "stack.cpp"
#include <stack_iterator.h>
#include <usr_stack.h>

#endif // STACK_H
