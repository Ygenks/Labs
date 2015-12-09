#ifndef STACK_ITERATOR_H
#define STACK_ITERATOR_H

#include<stack.h>

template <class T>
class stack_iterator
{
    private:
        stack_node<T>* node;
     public:
        stack_iterator(): node(NULL)
        {}
        stack_iterator(Stack<T>& s): node(s.head)
        {}
        stack_iterator(stack_iterator& i)
        {
            node->data = i.node->data;
            node->next = i.node->next;
        }
        stack_iterator& operator++()
        {
            node = node->next;
            return *this;
        }
        stack_iterator& operator++(int)
        {
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
        bool operator==(stack_iterator* i)
        {
            return node == i->node;
        }
        bool operator!=(stack_iterator* i)
        {
            return node != i->node;
        }
        bool operator!=(int& value)
        {
            return node->data != value;
        }
        stack_iterator& operator=(stack_iterator& i)
        {
            node->data = i.node->data;
            node->next = i.node->next;
            return *this;
        }
        stack_iterator& operator=(Stack<T>& st)
        {
            new (this) stack_iterator(st);
            return *this;
        }
        stack_iterator& operator=(int& i)
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
};

#endif // STACK_ITERATOR_H
