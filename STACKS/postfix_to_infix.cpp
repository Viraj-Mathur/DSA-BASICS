#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Function to check if a given character is an operator or not
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert postfix expression to infix expression
string postfixToInfix(string postfix) {
    stack<string> s;  // stack to store operands

    // Traverse through every character of the postfix expression
    for (int i = 0; i < postfix.length(); i++) {
        // If character is an operator, pop two operands from stack, add them to the operator, and push the result back to the stack
        if (isOperator(postfix[i])) {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = "(" + op2 + postfix[i] + op1 + ")";
            s.push(temp);
            }
        // If character is an operand, push it to the stack
        else {
            string temp(1, postfix[i]);
            s.push(temp);
        }
    }
    // Return the final infix expression
    return s.top();
}

// Main function to test the postfixToInfix function
int main() {
    string postfix = "ABCD-*EF+/";

    cout << "Postfix Expression: " << postfix << endl;

    string infix = postfixToInfix(postfix);

    cout << "Infix Expression: " << infix << endl;

    return 0;
}
