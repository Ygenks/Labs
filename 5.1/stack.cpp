#include <iostream>
#include <math.h>

using namespace std;

struct stack_node
{
    int data;
    stack_node* next;
    stack_node(): data(0), next(NULL)
    {}
    stack_node(int& value): data(value), next(NULL)
    {}
};

class usr_Stack_iterator
{

};

class Stack
{
    private:
        stack_node* head;
    public:
        friend class Stack_iterator;
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
        int pop();
        void push(int& value);
        void show();
        stack_node* search(int key);
        void replace(int rep_to, int rep_by);
        int median();
        int maximum();
        int minimum();
        int g_mean();
        bool is_empty()
        {
            return head == NULL? true : false;
        }
};

void Stack :: push(int& value)
{
    if(NULL == head)
    {
        head = new stack_node(value);
        return;
    }

    stack_node* node = new stack_node(value);
    node->next = head;
    head = node;
    return;
}

int Stack :: pop()
{
    if(true == is_empty())
        throw Empty("pop()");

    stack_node* del_node = head;
    int poped = del_node->data;
    head = head->next;
    delete del_node;
    return poped;
}

void Stack :: show()
{
    stack_node* node = head;
    while(NULL != node)
    {
        cout << node->data << endl;
        node = node->next;
    }
}

stack_node* Stack :: search(int key)
{
    stack_node* current = head;
    while(NULL != current)
        if(key == current->data)
            return current;
        else
            current = current->next;
    return NULL;
}
void Stack :: replace(int rep_to, int rep_by)
{
    stack_node* replaceable = search(rep_to);
    if(NULL == replaceable)
        throw No_elem("replace(int rep_to, int rep_by)");
    replaceable->data = rep_by;
    return;
}

int Stack :: median()
{
    int result = 0;
    int count = 0;
    stack_node* node = head;
    while(NULL != node)
    {
        result += node->data;
        node = node->next;
        count++;
    }
    return result/count;
}

int Stack :: maximum()
{
    if(true == is_empty())
        throw Empty("maximum()");
    int max = head->data;
    stack_node* node = head->next;
    while(NULL != node)
    {
        if(node->data > max)
            max = node->data;
        node = node->next;
    }
    return max;
}

int Stack :: minimum()
{
    if(true == is_empty())
        throw Empty("minimum()");
    int min = head->data;
    stack_node* node = head->next;
    while(NULL != node)
    {
        if(node->data < min)
            min = node->data;
        node = node->next;
    }
    return min;
}

int Stack :: g_mean()
{
    int result = 0;
    stack_node* node = head;
    while(NULL != node)
    {
        result *= node->data;
        node = node->next;
    }
    return sqrt(result);
}

class Stack_iterator
{
    private:
        stack_node* node;
     public:
        Stack_iterator(): node(NULL)
        {}
        Stack_iterator(Stack& s): node(s.head)
        {}
        Stack_iterator(Stack_iterator& i)
        {
            node->data = i.node->data;
            node->next = i.node->next;
        }
        Stack_iterator& operator++()
        {
            node = node->next;
            return *this;
        }
        Stack_iterator& operator++(int)
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
        bool operator==(Stack_iterator* i)
        {
            return node == i->node;
        }
        bool operator!=(Stack_iterator* i)
        {
            return node != i->node;
        }
        bool operator!=(int& value)
        {
            return node->data != value;
        }
        Stack_iterator& operator=(Stack_iterator& i)
        {
            node->data = i.node->data;
            node->next = i.node->next;
            return *this;
        }
        Stack_iterator& operator=(Stack& st)
        {
            new (this) Stack_iterator(st);
            return *this;
        }
        Stack_iterator& operator=(int& i)
        {
            node->data = i;
            return *this;
        }
        bool is_null()
        {
            return NULL == node? true : false;
        }
        int& get_data()
        {
            return node->data;
        }
};

int main()
{
    try
    {
        Stack s;


        for(int i = 0; i < 10; i++)
            s.push(i);
        Stack_iterator iter(s);
        for(iter; !iter.is_null(); iter++)
            cout << iter.get_data() << endl;

        cout << "Geomerty mean:" <<s.g_mean() << endl;
        cout << "Maximum:" <<s.maximum() << endl;
        cout << "Minimum:" <<s.minimum() << endl;
        cout << "Median:" <<s.median() << endl;

        s.replace(3, 4);

        s.show();

        stack_node* kek = s.search(5);
        cout << kek->data << endl;

        Stack s1;
        s1.pop();
    }
    catch(Stack::Empty)
    {}
    catch(Stack::No_elem)
    {}
    return 0;
}
