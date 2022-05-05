#include <iostream>
#define MAX 50
using namespace std;

class Queue
{
    int front = 0;
    int rear = 0;
    int arr[MAX];

public:
    void enque(int x)
    {
        if (rear == MAX - 1)
        {
            cout << "Overflow\n";
            return;
        }
        else
        {
            arr[rear] = x;
            rear++;
        }
    }

    void deque()
    {
        {
            for (int i = 0; i <= rear; i++)
            {
                arr[i] = arr[i + 1];
            }
            rear--;
        }
    }

    int queueFront()
    {
        return arr[front];
    }

    void display()
    {
        for (int i = 0; i < rear; i++)
        {
            cout << arr[i] << " ";
            cout << endl;
        }
    }

    bool isEmpty()
    {
        if (front == rear == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Queue q;
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    q.display();
    // cout << q.queueFront();
    cout << endl;
    q.deque();
    q.deque();
    // cout << q.queueFront();
    q.display();
    cout << q.isEmpty();
    q.deque();
    q.deque();
    cout << q.isEmpty();
}