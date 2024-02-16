#include <stack>
#include <string>
#include <iostream>

using namespace std;

int prec(char c) {
	if (c == '*')
		return 3;
	else if (c == '.')
		return 2;
	else if (c == '|')
		return 1;
	else
		return -1;
}

// Function to return associativity of operators
inline char associativity(char c) {
	return 'L'; // Default to left-associative
}

// The main function to convert infix expression
// to postfix expression
string infixToPostfix(string s) {
	stack<char> st;
	string result;

	for (size_t i = 0; i < s.length(); i++) {
		char c = s[i];

		// If the scanned character is
		// an operand, add it to the output string.
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;

		// If the scanned character is an
		// ‘(‘, push it to the stack.
		else if (c == '(')
			st.push('(');

		// If the scanned character is an ‘)’,
		// pop and add to the output string from the stack
		// until an ‘(‘ is encountered.
		else if (c == ')') {
			while (st.top() != '(') {
				result += st.top();
				st.pop();
			}
			st.pop(); // Pop '('
		}

		// If an operator is scanned
		else {
			while ((!st.empty() && prec(s[i]) < prec(st.top())) ||
				(!st.empty() && prec(s[i]) == prec(st.top()) &&
				associativity(s[i]) == 'L')) {
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	// Pop all the remaining elements from the stack
	while (!st.empty()) {
		result += st.top();
		st.pop();
	}

	return result;
}