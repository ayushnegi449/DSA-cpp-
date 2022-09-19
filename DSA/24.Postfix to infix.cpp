/*Postfix to Infix Conversion using Stack Data Structure (With C++ Program Code)

Rules for Postfix to Infix using stack DS –
Scan POSTFIX expression from LEFT to RIGHT
IF the incoming symbol is a OPERAND, PUSH it onto the Stack
IF the incoming symbol is a OPERATOR, POP 2 OPERANDs from the Stack, ADD this incoming OPERATOR in between the 2 OPERANDs, ADD ‘(‘ & ‘)’ to the whole expression & PUSH this whole new expression string back into the Stack.
At the end POP and PRINT the full INFIX expression from the Stack.


C++ Program to Postfix to Infix Conversion using Stack DS –*/

#include <bits/stdc++.h>
using namespace std;

string PostfixToInfix(string postfix)
{
    stack<string> s;
    string infix;

    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] >= 'a' && postfix[i] <= 'z' || postfix[i] >= 'A' && postfix[i] <= 'Z')
        {

            string operand(1, postfix[i]);
            // string operand ;
            // operand += postfix[i];
            s.push(operand);
        }
        else
        {
            string operator_2 = s.top();
            s.pop();

            string operator_1 = s.top();
            s.pop();

            infix = '(' + operator_1 + postfix[i] + operator_2 + ')';
            s.push(infix);
        }
    }

    return s.top();
}

int main()
{
    string postfix, infix;

    cout << "Enter the Postfix expression you want to convert to infix expression" << endl;
    cin >> postfix;

    cout << "\nPostfix expression is : " << postfix << endl;

    infix = PostfixToInfix(postfix);

    cout << "After conversion the infix expression is : " << infix;

    return 0;
}