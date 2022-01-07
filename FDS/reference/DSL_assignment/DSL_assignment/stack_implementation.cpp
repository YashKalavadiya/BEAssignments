#include <iostream>
#define MAX 10
using namespace std;

class Stack
{
    int a[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        if (top == -1)
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
        if (top == MAX - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int val)
    {
        if (!isFull())
        {
            a[++top] = val;
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            top--;
        }
    }

    void display()
    {
        int count = top;
        while (count >= 0)
        {
            cout << a[count] << " ";
            count--;
        }
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    cout << endl;
    s.pop();
    s.display();
    cout << endl;
    s.pop();
    s.pop();
    if (s.isEmpty())
    {
        cout << "stack is empty";
    }
    s.pop();
}