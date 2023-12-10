#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int key;
    int height;
    Node *left;
    Node *right;

    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree
{
private:
    Node *root;

    int height(Node *p)
    {
        if (p == nullptr)
            return 0;
        return p->height;
    }

    int balanceFactor(Node *p)
    {
        if (p == nullptr)
            return 0;
        return height(p->left) - height(p->right);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node *insert(Node *p, int key)
    {
        if (p == nullptr)
            return new Node(key);

        if (key < p->key)
            p->left = insert(p->left, key);
        else if (key > p->key)
            p->right = insert(p->right, key);
        else
            return p; // Duplicate keys are not allowed

        p->height = 1 + max(height(p->left), height(p->right));

        int balance = balanceFactor(p);

        // Left Heavy
        if (balance > 1)
        {
            if (key < p->left->key)
            {
                return rightRotate(p);
            }
            else
            {
                p->left = leftRotate(p->left);
                return rightRotate(p);
            }
        }

        // Right Heavy
        if (balance < -1)
        {
            if (key > p->right->key)
            {
                return leftRotate(p);
            }
            else
            {
                p->right = rightRotate(p->right);
                return leftRotate(p);
            }
        }

        return p;
    }

    Node *search(Node *p, int key)
    {
        if (p == nullptr || p->key == key)
            return p;

        if (key < p->key)
            return search(p->left, key);
        else
            return search(p->right, key);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key)
    {
        root = insert(root, key);
    }

    bool search(int key)
    {
        return search(root, key) != nullptr;
    }
};

int main()
{
    AVLTree avlTree;

    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);

    cout << "Search for 20: " << (avlTree.search(20) ? "Found" : "Not Found") << endl;
    cout << "Search for 40: " << (avlTree.search(40) ? "Found" : "Not Found") << endl;

    return 0;
}
