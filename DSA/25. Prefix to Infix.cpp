/*Prefix to Infix Conversion using Stack Data Structure (With C++ Program Code)

Rules for Prefix to Infix using stack DS –
1.Scan PREFIX expression from RIGHTto LEFT OR REVERSE the PREFIX expression and scan it from LEFT to RIGHT.
2.IF the incoming symbol is a OPERAND, PUSH it onto the Stack
3.IF the incoming symbol is a OPERATOR, POP 2 OPERANDs from the Stack, ADD this incoming OPERATOR in between the 2 OPERANDs, 
  ADD ‘(‘ & ‘)’ to the whole expression & PUSH this whole new expression string back into the Stack.
5.At the end POP and PRINT the full INFIX expression from the Stack.


C++ Program to Prefix to Infix Conversion using Stack DS –*/

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

string PrefixToInfix(string prefix)
{
    stack<string> s;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isOperand(prefix[i]))
        {
            string op(1, prefix[i]);
            // string op = prefix[i];
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op1 + prefix[i] + op2 + ")");
        }
    }
    return s.top();
}

int main()
{
    string infix, prefix;
    cout << "Enter a PREFIX Expression :" << endl;
    cin >> prefix;
    cout << "PREFIX EXPRESSION: " << prefix << endl;
    infix = PrefixToInfix(prefix);
    cout << endl
         << "INFIX EXPRESSION: " << infix;

    return 0;
}