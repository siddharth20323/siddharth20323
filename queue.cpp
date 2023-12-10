#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size) : front(-1), rear(-1), capacity(size)
    {
        arr = new int[capacity];
    }

    ~Queue()
    {
        delete[] arr;
    }

    void enqueue(int data)
    {
        if (isEmpty())
        {
            front = rear = 0;
            arr[rear] = data;
        }
        else if (rear < capacity - 1)
        {
            arr[++rear] = data;
        }
        else
        {
            cout << "Queue overflow!" << endl;
        }
    }

    int dequeue()
    {
        if (!isEmpty())
        {
            int data = arr[front];
            if (front == rear)
            {
                front = rear = -1; // Reset to empty queue
            }
            else
            {
                front++;
            }
            return data;
        }
        else
        {
            cout << "Queue underflow!" << endl;
            return -1;
        }
    }

    int peek()
    {
        if (!isEmpty())
        {
            return arr[front];
        }
        else
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }
};

int main()
{
    Queue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    cout << "Front element: " << queue.peek() << endl;

    cout << "Dequeue: " << queue.dequeue() << endl;

    cout << "Front element after dequeue: " << queue.peek() << endl;

    return 0;
}
