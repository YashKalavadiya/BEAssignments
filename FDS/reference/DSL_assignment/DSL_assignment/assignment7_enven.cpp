#include <iostream>
using namespace std;

class Node
{
    int x;
    Node *prev;
    Node *next;

public:
    Node()
    {
        x = 0;
        prev = next = NULL;
    }
    Node(int y)
    {
        x = y;
        prev = NULL;
        next = NULL;
    }
    friend class Binary;
};

class Binary
{
    Node *start;
    Node *last;

public:
    Binary()
    {
        start = last = NULL;
    }
    void preparebinary(int num)
    {
        start = new Node(num % 2);
        last = new Node(num % 2);
        num = num / 2;

        while (num > 0)
        {
            Node *newNode = new Node(num % 2);
            start->prev = newNode;
            newNode->next = start;
            start = start->prev;
            num = num / 2;
        }
    }

    void display()
    {
        Node *temp = start;
        while (temp != NULL)
        {
            cout << temp->x;
            temp = temp->next;
        }
    }
    Binary one_complement()
    {
        Node *temp = start;
        while (temp != NULL)
        {
            if (temp->x == 0)
            {
                temp->x = 1;
            }
            else
            {
                temp->x = 0;
            }
            temp = temp->next;
        }
    }
    Binary addition(Binary num)
    {
        Binary ans;
        Node *last1 = last;
        Node *last2 = num.last;

        if (last->x ==)
    }
};
int main()
{
    Binary b;
    int num;
    cout << "Enter the number:";
    cin >> num;
    b.preparebinary(num);
    b.display();
    cout << endl;
    Binary b2 = b.one_complement();
    b2.display();
}
