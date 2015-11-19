#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node* left,*right;

    Node():value(0),left(NULL),right(NULL)
    {}
    Node(int num):value(num), left(NULL),right(NULL)
    {}
    ~Node()
    {
        delete left;
        delete right;
    }
    int get_value()
    {
        return value;
    }
    Node* get_left()
    {
        return left;
    }
    Node* get_right()
    {
        return right;
    }
};

class Tree
{
    private:
        Node* Tree_Node;
        void add(int num, Node** root);
        void print(Node* Tree_Node);
        Node* search(int key, Node* node);
        void delete_Node(int num, Node **node);
    public:
        Tree():Tree_Node(NULL)
        {}
        /*~Tree(): ~Node()
        {
            delete Tree_Node;
        }*/
        int get_value()
        {
            return Tree_Node->get_value();
        }
        void add(int num);
        Node* search(int key);
        void delete_Node(int key);
        void print();
};

void Tree:: add(int num)
{
   add(num, &Tree_Node);
   return;
}

void Tree :: add(int num, Node** root)
{
    if(NULL == *root)
    {
        *root = new Node(num);
        return;
    }
    if(num <=(*root)->value)
        add(num, &(*root)->left);
    if(num > (*root)->value)
        add(num, &(*root)->right);

}

void Tree :: print()
{
    print(Tree_Node);
}

void Tree :: print(Node* node)
{
    if(NULL != node)
    {
        print(node->left);
        cout << node->value << ' ';
        print(node->right);
    }
    return;
}

Node* Tree :: search(int key)
{
    search(key, Tree_Node);
}

Node* Tree :: search(int key, Node* node)
{
    if (NULL != node)
    {
        if (key < node->value && NULL != node->left)
            search(key, node->left);
        if (key > node->value && NULL != node->right)
            search(key, node->right);
        if (key == node->value)
            return node;
    }
    else
        return NULL;
}

void Tree :: delete_Node(int key)
{
    delete_Node(key, &Tree_Node);
}

void Tree :: delete_Node(int key, Node **node)
{
    Node *l, *r;

    if (NULL == *node)
        return;

    if (key < (*node)->value)
        delete_Node(key, &(*node)->left);
    else if (key > (*node)->value )
        delete_Node(key, &(*node)->right);
    else
    {
        l = (*node)->left;
        r = (*node)->right;

        delete *node;
        *node = r;

        while (NULL != *node)
            node = &(*node)->left;
        *node = l;
    }
}

int main()
{
    Tree t;
    while(true)
    {
        int num = 0;

        cout << "enter number:" << endl;
        cin >> num;
        t.add(num);
        cout << "press q to break" << endl;
        char ans = 0;
        cin >> ans;
        if('q' == ans && true == cin.good())
        {
            cin.ignore(100, '\n');
            break;
        }
        cin.ignore(100, '\n');
        cin.clear();
    }
    t.print();
    Node *a = t.search(3);
    cout << a->get_value();
    /*t.delete_Node(3);
    t.print();*/
    return 0;
}
