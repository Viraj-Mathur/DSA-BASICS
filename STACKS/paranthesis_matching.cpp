#include <iostream>
#include <stack> 

using namespace std;

bool isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')')
        return true;
    else if (character1 == '{' && character2 == '}')
        return true;
    else if (character1 == '[' && character2 == ']')
        return true;
    else
        return false;
}

bool isBalanced(string exp) {
    stack<char> s;

    for (int i = 0; i < exp.length(); i++) {

        // if opening bracket, push onto stack
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            s.push(exp[i]);
        }

        // if closing bracket, pop and check for match
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            // if stack is empty, there is no opening bracket to match with
            if (s.empty()) {
                return false;
            }
            // if top of stack is not matching opening bracket, return false
            else if (!isMatchingPair(s.top(), exp[i])) {
                return false;
            }
            // if matching, pop the opening bracket
            else {
                s.pop();
            }
        }
    }
    // if stack is empty, all brackets have been matched
    // otherwise, there are unmatched brackets
    return s.empty();
}

int main() {
   string expression;
    cout << "Enter the expression to check for balanced parentheses: ";
    getline(cin, expression);
    if (isBalanced(expression)) {
        cout << "The expression is balanced" << endl;
    } else {
        cout << "The expression is not balanced" << endl;
    }
    return 0;
}
