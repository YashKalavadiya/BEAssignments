/* Queue Implementation */
/*
    Name: Mahadev V. Wardule
    Roll no.- 21288
    Batch: H2
*/

#include <iostream>
#define MAX 50
using namespace std;

class Queue
{
    int front;
    int rear;
    int arr[MAX];

public:
    Queue()
    {
        front = rear = -1;
    }
    void enque(int x)
    {
        if (rear == MAX - 1)
        {
            cout << "Overflow\n";
            return;
        }
        else
        {
            arr[++rear] = x;
        }
    }

    void deque()
    {
        {
            for (int i = 0; i < rear; i++)
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
        for (int i = 0; i <= rear; i++)
        {
            cout << arr[i] << " ";
            cout << endl;
        }
    }

    bool isEmpty()
    {
        if (front == rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (rear == MAX - 1)
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
    int ch, item;
    char ans;
    Queue q;

    do
    {
        cout << "\n Main Menu:";
        cout << "\n 1.ADD Job\n 2.Delete Job\n 3.Display Job Queue:";
        cout << "\n Enter your choice:";
        cin >> ch;

        switch (ch)
        {

        case 1:
            if (q.isFull())
                cout << "\n Can not insert the job";

            else
            {
                cout << "\n Enter the Job number:";
                cin >> item;
                q.enque(item);
            }
            break;

        case 2:
            if (q.isEmpty())
                cout << "\n Queue Underflow:";

            else
                q.deque();
            break;

        case 3:
            if (q.isEmpty())
                cout << "\n Job Queue is Empty:";

            else
                q.display();
            break;

        default:
            cout << "\n Wrong Choice:";
            break;
        }

        cout << "\n Do you want to continue?:";
        cin >> ans;
    } while (ans == 'Y' || ans == 'y');

    return 0;
}