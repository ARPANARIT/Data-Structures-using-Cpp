#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a character is an operator or not
bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    return false;
}

// Function to check precedence of operators
int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    }
    return -1;
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If character is an operand, add it to the output string
        if (isalnum(c)) {
            postfix += c;
        }
        // If character is a left parenthesis, push it onto the stack
        else if (c == '(') {
            s.push(c);
        }
        // If character is a right parenthesis, pop operators from the stack
        // and add them to the output string until a left parenthesis is encountered
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') {
                s.pop();
            }
        }
        // If character is an operator, pop operators from the stack
        // and add them to the output string until an operator of lower precedence is encountered
        else if (isOperator(c)) {
            while (!s.empty() && precedence(c) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop any remaining operators from the stack and add them to the output string
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix = "(a-b/c)*(a/k-l)";

    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << infixToPostfix(infix) << endl;

    return 0;
}
