#include <iostream>
using namespace std;
class node
{
public:
    int data;

    node *next;
    node(int value) : data(value), next(nullptr) {}
};
class circularll
{
private:
    node *head;

public:
    circularll() : head(nullptr) {}
    void insert(int x)
    {
        node *p = new node(x);
        if (head == nullptr)
        {
            head = p;
            head->next = head;
        }
        else
        {
            node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = p;
            p->next = head;
        }
    }
    void remove(int x)
    {
        if (head == nullptr)
        {
            return;
        }
        node *curr = head;
        node *prev = nullptr;
        while (curr->data != x && curr->next != head)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr->data != x)
        {
            cout << "element" << x << "not found";
            return;
        }
        if (curr == head)
        {
            if (curr->next = head)
            {
                head = nullptr;
            }
            else
            {
                prev = head;
                while (prev->next != head)
                {
                    prev = prev->next;
                }
                head = head->next;
                prev->next = head;
            }
        }
        else
        {
            prev->next = curr->next;
        }
        delete curr;
    }
    node *search(int x)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        node *curr = head;
        do
        {
            if (curr->data == x)
            {
                return curr;
            }
            curr = curr->next;
        } while (curr != head);

        return nullptr;
    }
      void display() {
        if (head == nullptr) {
             cout << "The list is empty." <<  endl;
            return;
        }

        node* curr = head;
        do {
             cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        cout <<  endl;
    }

};
int main()
{
    circularll ll;
    ll.insert (3);
    ll.insert (5);
    ll.insert (7);
    ll.insert (9);
    cout<<"linked list at beginning  ";
    ll.display(); 

   

    ll.remove(7);
    cout<<"linked list  after removing  ";
    ll.display();

     

    node *search=ll.search(3);
    if(search!=nullptr){
        cout<<"elemnet 3 found address  "<<search<<endl;
    }else{
        cout<<"not found "<<endl;
    }
    return 0;

}
