#include <bits/stdc++.h>

using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node()
    {
        next = NULL;
    }
    Node(int x)
    {
        data = x;
        next = NULL;
    }
    friend class Stack;
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        if (top == NULL)
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
        Node *temp = new Node(val);
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        if (!isEmpty())
        {
            Node *temp = top;
            top = top->next;
            delete (temp);
        }
    }

    void display()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
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