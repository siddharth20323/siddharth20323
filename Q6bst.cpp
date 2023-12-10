#include <iostream>
using namespace std;
class node
{
public:
    int data;

    node *left;
    node *right;
    node(int value) : data(value), left(nullptr), right(nullptr) {}
};
class BST
{
private:
    node *root;
    node *insert(node *p, int value)
    {
        if (p == nullptr)
        {
            return new node(value);
        }
        if (value < p->data)
        {
            p->left = insert(p->left, value);
        }
        else if (value > p->data)
        {
            p->right = insert(p->right, value);
        }
        return p;
    }
    node *min(node *p)
    {
        while (p->left != nullptr)
        {
            p = p->left;
        }
        return p;
    }
    node *deletenode(node *p, int value)
    {
        if (p == nullptr)
        {
            return nullptr;
        }
        if (value < p->data)
        {
            p->left = deletenode(p->left, value);
        }
        else if (value > p->data)
        {
            p->right = deletenode(p->right, value);
        }
        else
        {
            // when there is only 1child or no child....
            if (p->left == nullptr)
            {
                node *temp = p->right;
                delete p;
                return temp;
            }
            else if (p->right == nullptr)
            {
                node *temp = p->left;
                delete p;
                return temp;
            }
            node *temp = min(p->right);
            p->data = temp->data;
            p->right = deletenode(p->right, temp->data);
        }
        return p;
    }
    node *search(node *p, int value)
    {
        if (p == nullptr || p->data == value)
        {
            return p;
        }
        if (value < p->data)
        {
            return search(p->left, value);
        }
        else
        {
            return search(p->right, value);
        }
    }
    void preoder(node *p)
    {
        if (p != nullptr)
        {
            cout << p->data << " ";
            preoder(p->left);
            preoder(p->right);
        }
    }
    void inorder(node *p)
    {
        if (p != nullptr)
        {

            inorder(p->left);
            cout << p->data << " ";
            inorder(p->right);
        }
    }
    void postoder(node *p)
    {
        if (p != nullptr)
        {

            postoder(p->left);
            postoder(p->right);
            cout << p->data << " ";
        }
    }

public:
    BST() : root(nullptr) {}
    void insert(int value)
    {
        root = insert(root, value);
    }
    void deletenode(int value)
    {
        root = deletenode(root, value);
    }
    node *find(int value)
    {
        return search(root, value);
    }
    void display()
    {
        cout << "preorder";
        preoder(root);
        cout << endl;

        cout << "inorder";
        inorder(root);
        cout << endl;

        cout << " postoder";
        postoder(root);
        cout << endl;
    }
};
int main()
{
    BST bst;
    bst.insert(10);
    bst.insert(30);
    bst.insert(9);
    bst.insert(13);
    bst.insert(88);
    bst.insert(50);
    bst.insert(4);
    cout << "BST elements";
    bst.display();

    int searchv = 88;
    node *s = bst.find(searchv);
    if (s != nullptr)
    {
        cout << "elememnt" << searchv << "found" << endl;
    }
    else
    {
        cout << "elememnt" << searchv << "not found" << endl;
    }
    int removev = 9;
    cout << "removing" << removev << "from bst" << endl;
    bst.deletenode(removev);
    cout << "bst after removing" << endl;
    bst.display();
    return 0;
}
