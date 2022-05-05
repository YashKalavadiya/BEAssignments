/* Parentheses checker using stack */
/*
    Name: Mahadev V. Wardule
    Roll no.- 21288
    Batch: H2
*/

#include <bits/stdc++.h>
#define MAX 50
using namespace std;

class Stack
{
    char a[MAX];
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
    char Top()
    {
        if (!isFull())
        {
            return a[top];
        }
    }
};

class Expression
{
    string expression;

public:
    void get_expression()
    {
        cout << "Enter expresssion:";
        cin >> expression;
    }
    bool check_expression()
    {
        Stack s;
        for (int i = 0; i < expression.length(); i++)
        {
            if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            {
                s.push(expression[i]);
            }
            else
            {
                if (expression[i] == ')' and s.Top() == '(')
                {
                    s.pop(); //{[]}
                }

                else if (expression[i] == '}' and s.Top() == '{')
                {
                    s.pop();
                }
                else if (expression[i] == ']' and s.Top() == '[')
                {
                    s.pop();
                }
                else if ((expression[i] == ')' || expression[i] == '}' || expression[i] == ']') && s.isEmpty())
                {
                    return false;
                }
            }
        }

        if (s.isEmpty())
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
    Expression e;
    e.get_expression();
    if (e.check_expression())
    {
        cout << "Expression is well parenthesized\n";
    }
    else
    {
        cout << "Expression is not well parenthesized\n";
    }
}