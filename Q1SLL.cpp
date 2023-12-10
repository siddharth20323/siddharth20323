#include <iostream>
using namespace std;
class node
{
public:
    int data;

    node *next;
    node(int value) : data(value), next(nullptr) {}
};
class singlell
{
private:
    node *head;

public:
    singlell() : head(nullptr) {}

    void insert_beg(int x)
    {
        node *p = new node(x);
        p->next = head;
        head = p;
    }
    void insert_ith(int x, int pos)
    {
        node *p = new node(x);
        if (pos == 1 || head == nullptr)
        {
            p->next = head;
            head = p;
        }
        else
        {
            node *curr = head;
            for (int i = 1; i < pos - 1 && curr != nullptr; i++)
            {
                curr = curr->next;
            }
            if (curr != nullptr)
            {
                p->next = curr->next;
                curr->next = p;
            }
        }
    }

    void remove_beg()
    {
        if (head != nullptr)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void remove_ith(int pos)
    {
        if (pos == 1 || head == nullptr)
        {
             remove_beg();
        }
        else
        {
            node *curr = head;
            for (int i = 1; i < pos - 1 && curr != nullptr; i++)
            {
                curr = curr->next;
            }
            if (curr != nullptr && curr->next != nullptr)
            {
                node *temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
        }
    }

    node *search(int x)
    {
        node *curr = head;
        while (curr != nullptr)
        {
            if (curr->data = x)
            {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }

    void display()
    {
        node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};
int main()
{
    singlell ll;
    ll.insert_beg(3);
    ll.insert_beg(5);
    ll.insert_beg(7);
    ll.insert_beg(9);
    cout<<"linked list at beginning  ";
    ll.display(); 

    ll.insert_ith(10,2);
    cout<<"linmked list after inserting at 2nd position  ";
    ll.display();

    ll.remove_beg();
    cout<<"linked list  after removing at begining ";
    ll.display();

    ll.remove_ith(1);
    cout<<"removing at 1st postion  ";
    ll.display();

    node *search=ll.search(9);
    if(search!=nullptr){
        cout<<"elemnet 9 found address  "<<search<<endl;
    }else{
        cout<<"not found "<<endl;
    }
    return 0;

}
