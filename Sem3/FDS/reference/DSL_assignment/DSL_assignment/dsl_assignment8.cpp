#include <iostream>

using namespace std;
class Node
{
private:
public:
    int roll_number;
    Node *next;
    Node(int num)
    {
        roll_number = num;
        next = NULL;
    }

    friend class Linked_list;
};

class Linked_list
{
private:
public:
    Node *start, *last;
    Linked_list()
    {
        start = NULL;
        last = NULL;
    }

    void insert_at_end(int num)
    {
        Node *temp = new Node(num);
        if (this->start == NULL)
        {
            start = last = temp;
        }
        else
        {
            Node *count = start;
            while (count->next != NULL and count->roll_number != num)
            {
                count = count->next;
            }
            if (count->roll_number == num)
                return;
            count->next = temp;
            last = temp;
        }
    }

    void display()
    {
        Node *temp = start;
        while (temp != NULL)
        {
            cout << temp->roll_number << " ";
            temp = temp->next;
        }
    }

    Linked_list intersection(Linked_list b)
    {
        Linked_list answer;
        Node *temp1 = this->start;
        Node *temp2 = b.start;
        while (temp1 != NULL)
        {
            while (temp2 != NULL)
            {
                if (temp1->roll_number == temp2->roll_number)
                {
                    answer.insert_at_end(temp2->roll_number);
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
            temp2 = b.start;
        }
        return answer;
    }

    int length()
    {
        Node *temp = start;
        int len = 0;
        while (temp != NULL)
        {
            len += 1;
            temp = temp->next;
        }
        return len;
    }

    Linked_list set_union(Linked_list b)
    {
        Linked_list answer;
        Node *temp = start; //{1,2,3,4} ,{2,3,4,5}
        Node *temp2 = b.start;
        while (temp != NULL)
        {
            answer.insert_at_end(temp->roll_number);
            temp = temp->next;
        } // answer = {1,2,3,4}
        Node *temp3 = answer.start;
        int length;
        while (temp2 != NULL)
        {
            int count = 0;
            while (temp3 != NULL)
            {
                if (temp2->roll_number != temp3->roll_number)
                {
                    count += 1; // if element not in second list it not match with
                }               // any element and count equal to length of second list.
                temp3 = temp3->next;
            }
            length = answer.length();
            // cout << length << endl;
            if (count == length)
            {
                answer.insert_at_end(temp2->roll_number);
            }
            temp2 = temp2->next;
            temp3 = answer.start;
        }

        return answer;
    }
};

int main()
{
    Linked_list v, b, intersection, universal, setunion, neither_van_nor_butter, either_van_or_butter_not_both;
    int count;
    cout << "Enter the number of students: ";
    cin >> count;
    int number;
    char check;
    for (int i = 0; i < count; i++)
    {
        cout << "Enter your roll number: ";
        cin >> number;
        cout << "do you like vanilla?(y/n)" << endl;
        cin >> check;
        if (check == 'y')
        {
            v.insert_at_end(number);
        }
        cout << "do you like butterscotch?(y/n)" << endl;
        cin >> check;
        if (check == 'y')
        {
            b.insert_at_end(number);
        }
        universal.insert_at_end(number);
    }

    cout << "Universal: {";
    universal.display();
    cout << "}";
    cout << endl;
    cout << "Vanilla: {";
    v.display();
    cout << "}";
    cout << endl;
    cout << "Butter scotch: {";
    b.display();
    cout << "}";
    cout << endl;

    intersection = v.intersection(b);
    cout << "Set intersection: {";
    intersection.display();
    cout << "}";

    setunion = v.set_union(b);
    cout << "Set union: {";
    setunion.display();
    cout << "}";
    cout << endl
         << endl;

         
    // neither vanilla nor butterscotch
    Node *temp = universal.start;
    Node *temp1 = setunion.start;
    int counter = 0;
    while (temp != NULL)
    {
        while (temp1 != NULL)
        {
            if (temp1->roll_number == temp->roll_number)
            {
                counter++;
            }
            temp1 = temp1->next;
        }
        if (counter == 0)
        {
            neither_van_nor_butter.insert_at_end(temp->roll_number);
        }
        temp1 = setunion.start;
        temp = temp->next;
        counter = 0;
    }
    cout << "Student who dont like neither vanilla nor butterscotch:";
    cout << "{";
    neither_van_nor_butter.display();
    cout << "}";
    cout << endl;

    // either vanilla or butterscotch or not both
    Node *temp2 = setunion.start;
    Node *temp3 = intersection.start;
    int counter1 = 0;
    while (temp2 != NULL)
    {
        while (temp3 != NULL)
        {
            if (temp2->roll_number == temp3->roll_number)
            {
                counter1++;
            }
            temp3 = temp3->next;
        }
        if (counter1 == 0)
        {
            either_van_or_butter_not_both.insert_at_end(temp2->roll_number);
        }
        temp3 = intersection.start;
        temp2 = temp2->next;
        counter1 = 0;
    }
    cout << "Student who likes either vanilla or butterscotch but not both:";
    cout << "{";
    either_van_or_butter_not_both.display();
    cout << "}";
}