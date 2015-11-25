#include "tree.h"

template<class T>
void Tree<T>:: add(T value)
{
   add(value, &Tree_Node, NULL);
   return;
}

template <class T>
void Tree<T> :: add(T value, Node<T>** root, Node<T>* parent)
{
    if(NULL == *root)
    {
        *root = new Node<T>(value);
        (*root)->father = parent;
        return;
    }
    parent = *root;
    if(value <=(*root)->data)
        add(value, &(*root)->left, parent);
    if(value > (*root)->data)
        add(value, &(*root)->right, parent);

}

template <class T>
void Tree<T> :: add_left(T value, Node<T>** node)
{
    (*node)->left = new Node<T>(value);
    (*node)->left->father = *node;
}

template <class T>
void Tree<T> :: add_right(T value, Node<T>** node)
{
    (*node)->right = new Node<T>(value);
    (*node)->right->father = *node;
}

template <class T>
void Tree<T> :: add_root(T value, Node<T>** node)
{
    *node= new Node<T>(value);
}

template <class T>
void Tree<T> :: deconstruction()
{
    deconstruction(&Tree_Node);
}

template <class T>
void Tree<T> :: deconstruction(Node<T>** node)
{
    if(NULL != *node)
    {
        deconstruction(&(*node)->left);
        delete *node;
        deconstruction(&(*node)->right);
    }
}

template <class T>
void Tree<T> :: print()
{
    print(Tree_Node);
}

template <class T>
void Tree<T> :: print(Node<T>* node)
{
    if(NULL != node)
    {
        print(node->left);
        cout << node->data << ' ';
        print(node->right);
    }
    return;
}

template <class T>
Node<T>* Tree<T> :: search(T key)
{
    return search(key, Tree_Node);
}

template <class T>
Node<T>* Tree<T> :: search(T key, Node<T>* node)
{
    if (NULL != node)
    {

        if (key < node->data && NULL != node->left)
           return search(key, node->left);
        if (key > node->data && NULL != node->right)
           return search(key, node->right);
        if (key == node->data)
           return node;
    }
    return NULL;
}


template <class T>
void Tree<T> :: delete_Node(T key)
{
    Node<T>* del = search(key);

    if(NULL == del)
        return;
    if(NULL == del->left && NULL == del->right)
    {
        if(NULL == del->father->left)
           del->father->left = NULL;
        if(NULL == del->father->right)
           del->father->right = NULL;
        delete del;
    }else
    {
        Node<T>* replace = NULL;

        if(NULL != del->right)
        {
            replace = del->right;
            while(NULL != replace->left)
                replace = replace->left;
            if(del == del->father->left)
            {
                del->father->left = del->right;
                replace->left = del->left;
                del->left->father = replace;
            }
            else
            {
                del->father->right = del->right;
                replace->left = del->left;
                del->left->father = replace;
            }
            delete del;
        }
        else
        {
            if(del == del->father->right)
            {
                del->father->right = del->left;
                del->left->father = del->father;
            }
            else
            {
                del->father->left = del->left;
                del->left->father = del->father;
            }
            delete del;
        }
        return;
    }
}

template <class T>
void Tree<T> :: math_parse(char* exp)
{
    add_root('0', &Tree_Node);
    math_parse(exp,&Tree_Node);
}

template <class T>
void Tree<T> :: math_parse(char* exp,Node<T>** node)
{
    if('\0' == *exp)
    {
        //cerr << "Wrong expression: math_parse" << endl;
        return;
    }else
    if('(' == *exp)
    {
        add_left(*exp,node);
        math_parse(exp+1, &(*node)->left);
    }else
    if('+' == *exp  || '-' == *exp || '*' == *exp || '/'== *exp)
    {
        (*node)->data = *exp;
        add_right('n', node);
        math_parse(exp+1, &(*node)->right);
    }else
    if(*exp >= '0' && *exp <= '9')
    {
        (*node)->data = *exp;
        math_parse(exp+1, &(*node)->father);
    }else
    if(')' == *exp)
        math_parse(exp+1, &(*node)->father);
    else
        math_parse(exp+1, node);

}

template <class T>
int Tree<T> :: evaluate()
{
    return evaluate(Tree_Node);
}

template <class T>
int Tree<T> :: evaluate(Node<T>* node)
{
    if(NULL != node->left && NULL != node->right)
    {
        switch(node->data)
        {
            case '+':
            {
                return evaluate(node->left) + evaluate(node->right);
                break;
            }
            case '-':
            {
                return evaluate(node->left) - evaluate(node->right);
                break;
            }
            case '*':
            {
                return evaluate(node->left) * evaluate(node->right);
                break;
            }
            case '/':
            {
                return evaluate(node->left) / evaluate(node->right);
                break;
            }
        }
    }
    else
        return node->data - '0';
}
