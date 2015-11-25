#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

template <class T>
struct Node
{
    T data;
    Node *left, *right, *father;
    Node():data(0),left(NULL),right(NULL), father(NULL)
    {}
    Node(T value):data(value), left(NULL),right(NULL),father(NULL)
    {}
    ~Node()
    {}
};

template <class T>
class Tree
{
    private:
        Node<T>* Tree_Node;
        void add(T value, Node<T>** root, Node<T>* parent);
        void print(Node<T>* Tree_Node);
        Node<T>* search(T key, Node<T>* node);
        void deconstruction(Node<T>** node);
        void math_parse(char* exp,Node<T>** node);
        int evaluate(Node<T>* node);
    public:
        Tree():Tree_Node(NULL)
        {}
        ~Tree()
        {
            deconstruction();
        }
        void add(T value);
        void add_left(T value, Node<T>** node);
        void add_right(T value, Node<T>** node);
        void add_root(T value, Node<T>** node);
        Node<T>* search(T key);
        void delete_Node(T key);
        void print();
        void deconstruction();
        void math_parse(char* exp);
        int evaluate();
        bool is_empty()
        {
            if(NULL == Tree_Node->left && NULL == Tree_Node->right)
                return true;
            return false;
        }
};

#include "tree.cpp"

#endif // TREE_H
