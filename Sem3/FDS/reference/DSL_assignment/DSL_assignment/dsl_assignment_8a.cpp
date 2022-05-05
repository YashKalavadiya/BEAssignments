/*
Problem statement : Write a c++ program for storing appointment schedule for day.Appointments are bookedrandomly using linked list.Set start and end timeand min amd max duration for visit slot.Write function for-
a)Display free slots b)Book appointment c)Sort list based on time d)Cancel appointment
e)Sort list based on time using pointer manipulation.
*/

/*
    Name:Mahadev Wardule
    Roll no : 21288
    batch : H2
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
private:
    float startTime, endTime;
    Node *next;
    bool bookingStatus;

public:
    Node()
    {
        startTime = endTime = 00;
        next = NULL;
        bookingStatus = false;
    }
    Node(float starttime, float endtime, Node *nextptr = NULL, bool status = false)
    {
        startTime = starttime;
        endTime = endtime;
        bookingStatus = status;
        next = nextptr;
    }
    friend class Appointment;
};

class Appointment
{
private:
    Node *start, *end;

public:
    Appointment()
    {
        start = end = NULL;
    }

    void createAppointmentSlot(float starttime, float endtime)
    {
        Node *prev = start = new Node(starttime, starttime + 30);
        while (prev->endTime != endtime)
        {
            Node *current = new Node(prev->endTime, prev->startTime + 100);
            prev->next = current;
            prev = current;
        }
    }

    void display()
    {
        Node *temp = start;
        int i = 1;
        cout << "Slot no.   Start    End        Status\n";
        while (temp != NULL)
        {
            if (temp->bookingStatus == 0)
            {
                cout << i << "\t   " << fixed << setprecision(2) << temp->startTime / 100 << "     " << temp->endTime / 100 << "      "
                     << "Available";
            }
            else
            {
                cout << i << "\t   " << fixed << setprecision(2) << temp->startTime / 100 << "     " << temp->endTime / 100 << "      "
                     << "booked";
            }
            cout << endl;
            temp = temp->next;
            i++;
        }
    }

    void bookAppointment(float time)
    {
        Node *temp = start;
        while (temp != NULL)
        {
            if (time != (temp->startTime) / 100)
            {
                temp = temp->next;
            }
            else
            {
                break;
            }
        }
        if (temp == NULL)
        {
            cout << "Enter valid time slot!!\n";
            return;
        }
        if (temp->bookingStatus == 1)
        {
            cout << "Already booked!!!\n";
        }
        else
        {
            temp->bookingStatus = 1;
            cout << "Appointment booked successfully!!!\n";
        }
    }

    void cancelAppointment(float time)
    {
        Node *temp = start;
        while (time != (temp->startTime) / 100)
        {
            temp = temp->next;
        }
        if (temp->bookingStatus == 1)
        {
            temp->bookingStatus = 0;
            cout << "Booking cancelled successfully!!!\n";
        }
        else
        {
            cout << "This slot is already available!!\n";
        }
    }

    void displayFreeSlots()
    {
        int i = 1;
        Node *temp = start;
        cout << "Slot no.   Start    End        Status\n";
        while (temp != NULL)
        {
            if (temp->bookingStatus == 0)
            {
                cout << i << "\t   " << fixed << setprecision(2) << temp->startTime / 100 << "     " << temp->endTime / 100 << "      "
                     << "Available";
                cout << endl;
            }
            temp = temp->next;
        }
    }
};

int main()
{
    Appointment a;
    float starttime, endtime, time;
    cout << "\n\nEnter starting time:";
    cin >> starttime;
    cout << "Enter ending time:";
    cin >> endtime;
    a.createAppointmentSlot(starttime, endtime);

    int choice = 1;
    cout << "\n<-----Appointment Schedule ----->";

    do
    {
        cout << "\n1.Display all slots\n2.Display available slots\n3.Book a slot\n4.Cancel booked slot\n0.Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "All slots:\n";
            a.display();
            break;

        case 2:
            cout << "All available slots:\n";
            a.displayFreeSlots();
            break;

        case 3:
            cout << "Enter starting time of slot which you want to book:";
            cin >> time;
            a.bookAppointment(time);
            break;

        case 4:
            cout << "Enter starting time of slot which is to be cancelled:";
            cin >> time;
            a.cancelAppointment(time);
        }
        cout << "\n";
    } while (choice != 0 && choice <= 4 && choice > 0);

    if (choice == 0)
    {
        cout << "\nProgram exited!\n";
    }
    else
    {
        cout << "\nProgram terminated!!\n";
    }
    return 0;
}