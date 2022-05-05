#include <iostream>
using namespace std;

class Binary;
class Node
{
    int data;
    Node *next;
    Node *prev;

public:
    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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
        start = NULL;
        last = NULL;
    }

    void prepareBinary(int num)
    {
        start = last = new Node(num % 2);
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
            cout << temp->data;
            temp = temp->next;
        }
    }

    Binary onesComplement()
    {
        Binary result;
        Node *temp1 = start;
        result.start = result.last = new Node(!temp1->data);
        temp1 = temp1->next;

        while (temp1 != NULL)
        {
            Node *temp2 = new Node(!temp1->data);
            result.last->next = temp2;
            temp2->prev = result.last;
            result.last = temp2;
            temp1 = temp1->next;
        }

        return result;
    }

    Binary addition(Binary num)
    {
        Binary result;
        Node *temp1 = last;
        Node *temp2 = num.last;
        int carry = 0;
        int sum = 0;
        int add = carry + temp1->data + temp2->data;
        if (add > 1)
        {
            carry = 1;
        }
        if (add <= 1)
        {
            carry = 0;
        }
        if (add % 2 == 0)
        {
            sum = 0;
        }
        if (add % 2 == 1)
        {
            sum = 1;
        }
        result.start = result.last = new Node(sum);
        temp1 = temp1->prev;
        temp2 = temp2->prev;
        while (temp1 != NULL && temp2 != NULL)
        {
            int add = carry + temp1->data + temp2->data;
            if (add > 1)
            {
                carry = 1;
            }
            if (add <= 1)
            {
                carry = 0;
            }
            if (add % 2 == 0)
            {
                sum = 0;
            }
            if (add % 2 == 1)
            {
                sum = 1;
            }
            Node *temp3 = new Node(sum);
            result.start->prev = temp3;
            temp3->next = result.start;
            result.start = temp3;

            temp1 = temp1->prev;
            temp2 = temp2->prev;
        }

        while (temp1 != NULL)
        {
            add = temp1->data + carry;
            if (add > 1)
            {
                carry = 1;
            }
            if (add <= 1)
            {
                carry = 0;
            }
            if (add % 2 == 0)
            {
                sum = 0;
            }
            if (add % 2 == 1)
            {
                sum = 1;
            }
            Node *temp4 = new Node(sum);
            result.start->prev = temp4;
            temp4->next = result.start;
            result.start = temp4;
            temp1 = temp1->prev;
        }
        while (temp2 != NULL)
        {
            add = temp2->data + carry;
            if (add > 1)
            {
                carry = 1;
            }
            if (add <= 1)
            {
                carry = 0;
            }
            if (add % 2 == 0)
            {
                sum = 0;
            }
            if (add % 2 == 1)
            {
                sum = 1;
            }
            Node *temp5 = new Node(sum);
            result.start->prev = temp5;
            temp5->next = result.start;
            result.start = temp5;
            temp2 = temp2->prev;
        }
        if (temp1 == NULL && temp2 == NULL && carry == 1)
        {
            Node *temp5 = new Node(carry);
            result.start->prev = temp5;
            temp5->next = result.start;
            result.start = temp5;
        }

        return result;
    }

    Binary twosComplement()
    {
        Binary temp;
        temp.start = temp.last = new Node(1);
        Binary result, ones_complement;
        ones_complement = onesComplement();
        result = ones_complement.addition(temp);

        return result;
    }
};

int main()
{
    int num, num1;
    Binary n1, n2, n3;
    int choice = 1;
    cout << "\n<--Binary Operations-->";
    cout << "\n1.Prepare binary\n2.One's Complement\n3.Two's Complement\n4. Addition\n0.Exit";

    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Number in decimal: ";
            cin >> num;
            n1.prepareBinary(num);
            cout << "Binary number: ";
            n1.display();
            break;

        case 2:
            cout << "Enter number in decimal: ";
            cin >> num;
            n1.prepareBinary(num);
            cout << "Binary number: ";
            n1.display();
            cout << "\nOne's Complement: ";
            n2 = n1.onesComplement();
            n2.display();
            break;

        case 3:
            cout << "Enter number in decimal : ";
            cin >> num;
            n1.prepareBinary(num);
            cout << "Binary number: ";
            n1.display();
            cout << "\nTwos complement: ";
            n3 = n1.twosComplement();
            n3.display();
            break;

        case 4:
            cout << "Enter two numbers in decimal: ";
            cin >> num >> num1;
            n1.prepareBinary(num);
            n2.prepareBinary(num1);
            n1.display();
            cout << " + ";
            n2.display();
            cout << "= ";
            n3 = n1.addition(n2);
            n3.display();
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