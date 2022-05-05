/* Infix to postfix conversion */

/*
    Name:Mahadev V. Wardule
    Roll no. - 21288
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
    string infix, postfix;

public:
    Expression()
    {
        infix = "";
        postfix = "";
    }
    void input_infix()
    {
        cout << "Input string in infix form:";
        cin >> infix;
    }

    bool isOperand(char a)
    {
        if (((int(a) >= 48) && (int(a) <= 57)) || ((int(a) >= 97) && (int(a) <= 122)) || ((int(a) >= 65) && (int(a) <= 90)))
        {
            return true;
        }
        return false;
    }

    bool isOpeningParentheses(char a)
    {
        if (a == '(' || a == '[' || a == '{')
        {
            return true;
        }
        return false;
    }

    bool isClosingParentheses(char a)
    {
        if (a == ')' || a == '}' || a == ']')
        {
            return true;
        }
        return false;
    }

    bool isOperator(char a)
    {
        if (a == '+' || a == '-' || a == '*' || a == '/' || a == '^')
        {
            return true;
        }
        return false;
    }

    int precedenceOrder(char a)
    {
        if (a == '+' || a == '-')
        {
            return 1;
        }
        else if (a == '*' || a == '/')
        {
            return 2;
        }
        else if (a == '^')
        {
            return 3;
        }
    }

    string infixToPostfix()
    {
        Stack s;
        for (int i = 0; i < infix.length(); i++)
        {
            if (isOperand(infix[i]))
            {
                postfix = postfix + infix[i];
            }

            else if (isOpeningParentheses(infix[i]))
            {
                s.push(infix[i]);
            }
            else if (isOperator(infix[i]))
            {
                while ((!s.isEmpty()) && (!isOpeningParentheses(s.Top())) && (precedenceOrder(s.Top()) >= precedenceOrder(infix[i])))
                {
                    postfix = postfix + s.Top();
                    s.pop();
                }
                s.push(infix[i]);
            }

            else if (isClosingParentheses(infix[i]))
            {
                while (!s.isEmpty() && !isOpeningParentheses(s.Top()))
                {
                    postfix = postfix + s.Top();
                    s.pop();
                }
                s.pop();
            }
        }
        // cout<<postfix;
        while (!s.isEmpty())
        {
            postfix = postfix + s.Top();
            s.pop();
        }

        return postfix;
    }
};

int main()
{
    Expression a;
    string answer;
    a.input_infix();
    answer = a.infixToPostfix();
    cout << answer;
}