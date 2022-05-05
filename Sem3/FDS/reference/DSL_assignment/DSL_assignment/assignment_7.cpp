#include <bits/stdc++.h>

using namespace std;

class Seatnode
{
    int ticket_no;
    Seatnode *next;
    Seatnode *prev;
    bool status;

public:
    Seatnode(int ticket, bool stat = false)
    {
        ticket_no = ticket;
        next = NULL;
        prev = NULL;
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
            headers[i] = new Seatnode(i);
            Seatnode *temp = headers[i];
            for (int j = 0; j < 6; j++)
            {
                /* code */
                Seatnode *new_node = new Seatnode(j);
                temp->next = new_node;
                new_node->prev = temp;
                temp = new_node;
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
    cout << "\n\n*********** MAIN MENU ************\n\n";
    cout << "1.Display state of theatre.\n";
    cout << "2.Book a seat in theatre.\n";
    cout << "3.Cancel a seat in theatre.\n";
    cout << "4.Exit\n";
    cout << "********************************\n";

    while (true)
    {
        cout << "Enter the choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            a.display();
            break;

        case 2:
            a.book_a_seat();
            break;

        case 3:
            a.seat_cancellation();
            break;

        case 4:
            cout << "********** Thank You ***********\n";
            return 0;

        default:
            cout << "Enter Right choice..\n";
        }
    }
}