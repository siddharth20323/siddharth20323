#include <iostream>
using namespace std;
class node
{
public:
    int data;

    node *next;
    node *prev;
    node(int value) : data(value), next(nullptr), prev(nullptr) {}
};
class doublell
{
private:
    node *head;
    node *tail;

public:
    doublell() : head(nullptr), tail(nullptr) {}
    void insert_beg(int x)
    {
        node *p = new node(x);
        if (head ==nullptr)
        {
            head = tail = p;
        }
        else
        {
            p->next = head;
            head->prev = p;
            head = p;
        }
    }
    void insert_end(int x)
    {
        node *p = new node(x);
        if (tail == nullptr)
        {
            head = tail = p;
        }
        else
        {
            p->prev = tail;
            tail->next = p;
            tail = p;
        }
    }

    void remove_beg()
    {
        if (head!= nullptr)
        {
            node *temp = head;
            if (head == tail)
            {
                head = tail=nullptr;
            }
            else
            {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
        }
    }
    void remove_end(){
        if(tail !=nullptr){
            node * temp=tail;
            if(head==tail){
                head=tail=nullptr;

            }
            else{

                tail=tail->prev;
                tail->next=nullptr;
            }
            delete temp;
        }
    }
    void display(){
        node *curr=head;
        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->next;

        }
        cout<<endl;
    }
};

 int main()
{
    doublell ll;
    ll.insert_beg(10);
    ll.insert_beg(15);
    ll.insert_beg(20);
    ll.insert_beg(25);
    cout<<"linked list at beginning  ";
    ll.display(); 

    ll.insert_end(30);
    cout<<"linmked list after inserting at  end ";
    ll.display();

    ll.remove_beg();
    cout<<"linked list  after removing at begining ";
    ll.display();

    ll.remove_end();
    cout<<"removing at  end ";
    ll.display();
}