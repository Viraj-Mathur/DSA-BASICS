#include <iostream>
#include <stack>
using namespace std;

// Function to return the precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string infix)
{
    string postfix = "";
    stack<char> st;
    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
        if (isalpha(c))  // if operand, add to postfix
            postfix += c;
        else if (c == '(')  // if opening bracket, push to stack
            st.push(c);
        else if (c == ')')  // if closing bracket, pop stack until matching opening bracket
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();  // remove matching opening bracket
        }
        else  // if operator, check precedence and add to postfix
        {
            while (!st.empty() && precedence(c) <= precedence(st.top()))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())  // pop remaining operators from stack and add to postfix
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main()
{
    string infix = "A*B-(C-D)/(E+F)";
    string postfix = infixToPostfix(infix);
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
