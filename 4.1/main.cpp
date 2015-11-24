#include <iostream>
#include <string>

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
    public:
        Tree():Tree_Node(NULL)
        {}
        ~Tree()
        {
            deconstruction();
        }
        void add(T value);
        Node<T>* search(T key);
        void delete_Node(T key);
        void print();
        void deconstruction();
};

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

int main()
{

    return 0;
}
