/*Prefix to Postfix Conversion using Stack Data Structure (With C++ Program Code)

Rules for Prefix to Postfix using stack DS –
1.Scan PREFIX expression from RIGHT to LEFT
2.IF the incoming symbol is a OPERAND, PUSH it onto the Stack
3.IF the incoming symbol is a OPERATOR, POP 2 OPERANDs from the Stack, ADD this incoming OPERATOR in before the 2 OPERANDs & 
  PUSH this whole new expression string back into the Stack.
4.At the end POP and PRINT the full POSTFIX expression from the Stack.

C++ Program to Postfix to Prefix Conversion using Stack DS –*/

#include <iostream>
#include <stack>

using namespace std;

bool isOperand(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string PrefixToPostfix(string prefix)
{
    stack<string> s;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isOperand(prefix[i]))
        {
            string op(1, prefix[i]);
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push(op1 + op2 + prefix[i]);
        }
    }

    return s.top();
}

int main()
{

    string prefix, postfix;
    cout << "Enter a PREFIX Expression :" << endl;
    cin >> prefix;
    cout << "PREFIX EXPRESSION: " << prefix << endl;
    postfix = PrefixToPostfix(prefix);
    cout << endl
         << "POSTFIX EXPRESSION: " << postfix;

    return 0;
}