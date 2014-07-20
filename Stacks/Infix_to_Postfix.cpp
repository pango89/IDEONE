#include <iostream>
#include <cstdio> 
#include <stack> 

// A utility function to check if the given character is operand
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
 
// A utility function to return precedence of a given operator
// Higher returned value means higher precedence
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}
 
 
// The main function that converts given infix expression
// to postfix expression. 
void infixToPostfix(char* exp)
{
    int i, k;
   
    // Create a stack of capacity equal to expression size 
    stack<char> s1;    
    for (i = 0, k = -1; exp[i]; ++i)
    {
         // If the scanned character is an operand, add it to output.
        if (isOperand(exp[i]))
            exp[++k] = exp[i];
         
        // If the scanned character is an ‘(‘, push it to the stack.
        else if (exp[i] == '(')
            s1.push(exp[i]);
        
        //  If the scanned character is an ‘)’, pop and output from the stack 
        // until an ‘(‘ is encountered.
        else if (exp[i] == ')')
        {
            while (!s1.empty() && s1.top() != '(')
			{
                exp[++k] = s1.top();
				s1.pop();
			}
            if (!s1.empty() && s1.top() != '(')
                return; // invalid expression                
            else
			{
                s1.pop();//remove the closing Bracket
			}
        }
        else // an operator is encountered
        {
            while (!s1.empty() && Prec(exp[i]) <= Prec(s1.top()))
			{
                exp[++k] = s1.top();
				s1.pop();
			}
            s1.push(exp[i]);
        } 
    }
 
    // pop all the operators from the stack
    while (!s1.empty())
	{
        exp[++k] = s1.top();
		s1.pop();
	}
 
    exp[++k] = '\0';
    printf( "%s\n", exp );
}
 
// Driver program to test above functions
int main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}