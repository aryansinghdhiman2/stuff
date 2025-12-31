/*
File: Parse.h
*/

#ifndef __PARSE__H__

#define __PARSE__H__

#include <stack>
#include <string>
#include <iostream>

using string = std::string;

/*
Function: prec

Checks precedence of a character

Parameters:
	c - The character whose precedence is to be checked
*/
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

/*
Function: associativity
Returns associtivity

*/
inline char associativity(char c) {
	return 'L'; // Default to left-associative
}

/*
Function: infixToPostfix
Converts an infix string to postfix string

Returns: A postfix String

Parameters:
	s - An infix string

*/
string infixToPostfix(string s) {
	std::stack<char> st;
	string result;

	for (size_t i = 0; i < s.length(); i++) {
		char c = s[i];

		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;

		else if (c == '(')
			st.push('(');

		else if (c == ')') {
			while (st.top() != '(') {
				result += st.top();
				st.pop();
			}
			st.pop();
		}

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

	while (!st.empty()) {
		result += st.top();
		st.pop();
	}

	return result;
}

#endif