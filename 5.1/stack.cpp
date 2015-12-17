#include "stack.h"

template <class T>
void Stack<T> :: push(T value)
{
    if(NULL == head)
    {
        head = new stack_node<T>(value);
        return;
    }

    stack_node<T>* node = new stack_node<T>(value);
    node->next = head;
    head = node;
    return;
}
template <class T>
T Stack<T> :: pop()
{
    if(true == is_empty())
        throw Empty("pop()");

    stack_node<T>* del_node = head;
    T poped = del_node->data;
    head = head->next;
    delete del_node;
    return poped;
}

template <class T>
void Stack<T>  :: show()
{
    stack_node<T>* node = head;
    while(NULL != node)
    {
        cout << node->data << endl;
        node = node->next;
    }
}

template <class T>
stack_node<T>* Stack<T> :: search(T key)
{
    stack_node<T>* current = head;
    while(NULL != current)
        if(key == current->data)
            return current;
        else
            current = current->next;
    return NULL;
}
template <class T>
void Stack<T> :: replace(T rep_to, T rep_by)
{
    stack_node<T>* replaceable = search(rep_to);
    if(NULL == replaceable)
        throw No_elem("replace(T rep_to, T rep_by)");
    replaceable->data = rep_by;
    return;
}

template <class T>
T Stack<T> :: median()
{
    T result = 0;
    T count = 0;
    stack_node<T>* node = head;
    while(NULL != node)
    {
        result += node->data;
        node = node->next;
        count++;
    }
    return result/count;
}

template <class T>
T Stack<T> :: maximum()
{
    if(true == is_empty())
        throw Empty("maximum()");
    T max = head->data;
    stack_node<T>* node = head->next;
    while(NULL != node)
    {
        if(node->data > max)
            max = node->data;
        node = node->next;
    }
    return max;
}

template <class T>
T Stack<T> :: minimum()
{
    if(true == is_empty())
        throw Empty("minimum()");
    T min = head->data;
    stack_node<T>* node = head->next;
    while(NULL != node)
    {
        if(node->data < min)
            min = node->data;
        node = node->next;
    }
    return min;
}

template <class T>
T Stack<T> :: g_mean()
{
    T result = 0;
    stack_node<T>* node = head;
    while(NULL != node)
    {
        result *= node->data;
        node = node->next;
    }
    return sqrt(result);
}
