/*Infix to Prefix Conversion using Stack Data Structure (With C++ Program Code)

Rules for Infix to Prefix using stack DS –
Reverse infix expression & swap ‘(‘ to ”)’ & ‘)’ to ”(‘
Scan Expression from Left to Right
Print OPERANDs as the arrive
If OPERATOR arrives & Stack is empty, PUSH to stack
IF incoming OPERATOR has HIGHER precedence than the TOP of the Stack, PUSH it on stack
IF incoming OPERATOR has EQUAL precedence with TOP of Stack && incoming OPERATOR is ‘^’,  POP & PRINT TOP of Stack. Then test the incoming OPERATOR against the NEW TOP of stack.
IF incoming OPERATOR has EQUAL precedence  with TOP of Stack, PUSH it on Stack.
IF incoming OPERATOR has LOWER precedence than the TOP of the Stack, then POP and PRINT the TOP. Then test the incoming OPERATOR against the NEW TOP of stack.
At the end of Expression, POP & PRINT all OPERATORS from the stack
IF incoming SYMBOL is ‘(‘ PUSH it onto Stack.
IF incoming SYMBOL is ‘)’ POP the stack & PRINT  OPERATORs till ‘(‘ is found or Stack Empty.  POP out that ‘(‘ from stack
IF TOP of stack is ‘(‘ PUSH OPERATOR on Stack
At the end Reverse output string again.

C++ Program to Infix to Prefix Conversion using Stack DS –*/

#include <bits/stdc++.h>
using namespace std;

bool isOperator(char i)
{
    if (i == '+' || i == '-' || i == '/' || i == '*' || i == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int precedence(char i)
{
    if (i == '^')
        return 3;
    else if (i == '*' || i == '/')
        return 2;
    else if (i == '+' || i == '-')
        return 1;
    else
        return -1;
}
string infixToPrefix(stack<char> s, string infix)
{
    string prefix;

    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
        {
            prefix += infix[i];
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (s.top() != '(' && !s.empty())
            {
                prefix += s.top();
                s.pop();
            }
            if (s.top() == '(')
            {
                s.pop();
            }
        }
        else if (isOperator(infix[i]))
        {
            if (s.empty())
            {
                s.push(infix[i]);
            }
            else if (precedence(infix[i]) > precedence(s.top()))
            {
                s.push(infix[i]);
            }
            else if (precedence(infix[i]) == precedence(s.top()) && infix[i] == '^')
            {
                while (precedence(infix[i]) == precedence(s.top()) && infix[i] == '^')
                {
                    prefix += s.top();
                    s.pop();
                }
                s.push(infix[i]);
            }
            else if (precedence(infix[i]) == precedence(s.top()))
            {
                s.push(infix[i]);
            }
            else
            {

                while (precedence(infix[i]) < precedence(s.top()) && !s.empty())
                {
                    prefix += s.top();
                    s.pop();
                }

                s.push(infix[i]);
            }
        }
    }

    while (!s.empty())
    {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main()
{
    string infix, prefix;

    cout << "Enter the infix expression you want to convert to prefix expression" << endl;
    cin >> infix;

    cout << "\nInfix expression is : " << infix << endl;

    stack<char> s;

    prefix = infixToPrefix(s, infix);

    cout << "After conversion the prefix expression is : " << prefix;

    return 0;
}