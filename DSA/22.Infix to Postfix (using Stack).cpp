/*nfix to Postfix Conversion using Stack Data Structure (With C++ Program Code)

Rules for Infix to postfix using stack DS –

1.Scan Expression from Left to Right
2.Print OPERANDs as the arrive
3.If OPERATOR arrives & Stack is empty, push this operator onto the stack
4.IF incoming OPERATOR has HIGHER precedence than the TOP of the Stack, push it on stack
5.IF incoming OPERATOR has LOWER precedence than the TOP of the Stack, then POP and print the TOP. Then test the incoming operator against the NEW TOP of stack.
6.IF incoming OPERATOR has EQUAL precedence with TOP of Stack, use ASSOCIATIVITY Rules.

6.1For ASSOCIATIVITY of LEFT to RIGHT –
6.1a-POP and print the TOP of stack, then push the incoming OPERATOR

6.2.For ASSOCIATIVITY of RIGHT to LEFT –
6.2a-PUSH incoming OPERATOR on stack.

7.At the end of Expression, POP & print all  OPERATORS from the stack

8.IF incoming SYMBOL is ‘(‘ PUSH it onto Stack.
9.IF incoming SYMBOL is ‘)’ POP the stack and print OPERATORs till ‘(‘ is found. POP that ‘(‘
10.IF TOP of stack is ‘(‘ PUSH OPERATOR on Stack*/

#include <bits/stdc++.h>
using namespace std;

bool isOperator(char infix)
{
    if (infix == '+' || infix == '-' || infix == '*' || infix == '/' || infix == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int precedence(char infix)
{
    if (infix == '^')
        return 3;

    else if (infix == '*' || infix == '/')
        return 2;

    else if (infix == '+' || infix == '-')
        return 1;

    else
        return -1;
}

string infixToPostfix(stack<char> stack, string infix)
{
    string postfix;
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            stack.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (stack.top() != '(' && !stack.empty())
            {
                postfix += stack.top();

                stack.pop();
            }
            if (stack.top() == '(')
            {
                stack.pop();
            }
        }
        else if (isOperator(infix[i]))
        {
            if (stack.empty())
            {
                stack.push(infix[i]);
            }
            else if (precedence(infix[i]) > precedence(stack.top()))
            {
                stack.push(infix[i]);
            }
            else if (precedence(infix[i]) == precedence(stack.top()) && infix[i] == '^')
            {
                stack.push(infix[i]);
            }
            else
            {
                while (!stack.empty() && precedence(infix[i]) <= precedence(stack.top()))
                {
                    postfix += stack.top();
                    stack.pop();
                }
                stack.push(infix[i]);
            }
        }
    }
    while(!stack.empty())
    {
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}
int main()
{
    string postfix, infix;

    cout << "Enter the infix expression you want to convert to postfix expression\n";
    cin >> infix;

    cout << "\nBefore conversion i.e Infix expression : " << infix;

    stack<char> s;

    postfix = infixToPostfix(s, infix);

    cout << "\n\nAfter conversion i.e Postfix expression : " << postfix;

    return 0;
}