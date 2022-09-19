What is Prefix, Infix & Postfix Expressions ? Why do we need them ?

What is an Expression?
An Expression is a combination of symbols that can be numbers (constants), variables, operations, 
symbols of grouping and other punctuation written is a specific format/way.


infix expression example
Depending on how the expression is written, we can classify it into 3 categories –

1) Prefix –
An expression is called the prefix expression if the operator appears in the expression before the operands. Simply of the form (operator operand1 operand2). E.g. +AB

2) Infix –
An expression is called the infix expression if the operator appears in the expression in between the operands. Simply of the form (operand1 operator operand2). E.g. A+B

3) Postfix –
An expression is called the postfix expression if the operator appears in the expression after the operands. Simply of the form (operand1 operand2 operator). E.g. AB+

Order of Operations(Operator Precedence) –

1) Parentheses – {}, [], ()
2) Exponents(Right to Left) – A^B, 2^3^4
3) Multiplication & Division(Left to Right) – A*B/C
4) Addition & Subtraction(Left to Right) – A + B – C

Associativity –
Associativity describes the rule where operators with the same precedence appear in an expression. For example,
in expression a + b − c, both + and – have the same precedence, then which part of the expression will be evaluated first, 
is determined by associativity of those operators.

Why do we need 3 different expressions ?
Infix expressions are human readable but not efficient for machine reading
Prefix and Postfix do not need the concept of precedence & associativity hence it becomes highly efficient to parse expressions in prefix or postfix formats.
