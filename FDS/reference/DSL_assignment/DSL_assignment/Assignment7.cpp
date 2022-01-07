#include <bits/stdc++.h>

using namespace std;

class Seatnode
{
    int ticket_no;
    Seatnode *next;
    bool status;

public:
    Seatnode(int ticket, bool stat = false)
    {
        ticket_no = ticket;
        next = NULL;
        status = stat;
    }

    friend class Cinemax;
};

class Cinemax
{
    Seatnode *headers[10];

public:
    Cinemax()
    {
        for (int i = 0; i < 10; i++)
        {
            /* code */
            headers[i] = NULL;
        }
    }
    void prepare_theatre()
    {
        for (int i = 0; i < 10; i++)
        {
            /* code */
            headers[i] = new Seatnode(0);
            Seatnode *temparary = headers[i];
            for (int j = 0; j < 6; j++)
            {
                /* code */
                Seatnode *new_node = new Seatnode(0);
                temparary->next = new_node;
                temparary = new_node;
            }
        }
    }

    void display()
    {
        cout << "   ";
        for (int i = 0; i < 7; i++)
        {
            /* code */
            cout << i << "  ";
        }
        cout << endl;

        for (int i = 0; i < 10; i++)
        {
            /* code */
            cout << i << "  ";
            Seatnode *temp = headers[i];
            while (temp != NULL)
            {
                cout << temp->status << "  ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void book_a_seat()
    {
        int row, column;
        cout << "Enter row number:";
        cin >> row;
        cout << "Enter column number:";
        cin >> column;
        Seatnode *temp = headers[row];
        int i = 0;
        while (i < column)
        {
            /* code */
            temp = temp->next;
            i++;
                }
        temp->status = true;
    }
    void seat_cancellation()
    {
        int row, column;
        cout << "Enter row of seat which is to be cancelled:";
        cin >> row;
        cout << "Enter column of seat which is to be cancelled:";
        cin >> column;
        Seatnode *temp = headers[row];
        int i = 0;
        while (i != column)
        {
            /* code */
            temp = temp->next;
            i++;
        }
        temp->status = false;
    }
};
int main()
{

    Cinemax a;
    a.prepare_theatre();
    a.display();
    a.book_a_seat();
    a.display();
    a.seat_cancellation();
    a.display();
}