#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int precedence(char c)
{
    if (c == '*')
        return 3;
    else if (c == '.')
        return 2;
    else if (c == '+')
        return 1;
    return -1;
}
char associativity(char c)
{
    return 'L'; // Default to left-associative
}

string infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // If the scanned character is an operand, add it to the output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // If the scanned character is an ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ‘)’ pop and add to the output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop(); // Pop '('
        }
        // If an operator is scanned
        else
        {
            while (!st.empty() && precedence(s[i]) < precedence(st.top()) ||
                   !st.empty() && precedence(s[i]) == precedence(st.top()) &&
                       associativity(s[i]) == 'L')
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    // cout << result << endl;
    return result;
}

class Node
{
public:
    vector<int> a[2], eps;
    bool f = 0;
};

vector<Node> node;
stack<int> node_stk;
int n_size;
Node initial_state;

void alphabet(int i)
{
    node.push_back(initial_state);
    node.push_back(initial_state);
    node[n_size].a[i].push_back(n_size + 1);

    node_stk.push(n_size);
    n_size++;
    node_stk.push(n_size);
    n_size++;
}

void or_()
{
    node.push_back(initial_state);
    node.push_back(initial_state);

    int d = node_stk.top();
    node_stk.pop();
    int c = node_stk.top();
    node_stk.pop();
    int b = node_stk.top();
    node_stk.pop();
    int a = node_stk.top();
    node_stk.pop();

    node[n_size].eps.push_back(a);
    node[n_size].eps.push_back(c);
    node[b].eps.push_back(n_size + 1);
    node[d].eps.push_back(n_size + 1);

    node_stk.push(n_size);
    n_size++;
    node_stk.push(n_size);
    n_size++;
}
void and_()
{
    int d = node_stk.top();
    node_stk.pop();
    int c = node_stk.top();
    node_stk.pop();
    int b = node_stk.top();
    node_stk.pop();
    int a = node_stk.top();
    node_stk.pop();
    node[b].eps.push_back(c);
    node_stk.push(a);
    node_stk.push(d);
}

void closure()
{
    node.push_back(initial_state);
    node.push_back(initial_state);

    int b = node_stk.top();
    node_stk.pop();
    int a = node_stk.top();
    node_stk.pop();

    node[n_size].eps.push_back(a);
    node[n_size].eps.push_back(n_size + 1);
    node[b].eps.push_back(a);
    node[b].eps.push_back(n_size + 1);

    node_stk.push(n_size);
    n_size++;
    node_stk.push(n_size);
    n_size++;
}

// }
void display_nfa()
{
    cout << endl
         << endl;
    cout << "Transition Table: " << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "State\t|\ta\t|\tb\t|\tepsilon\t|acceptingstate|" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    for (int i = 0; i < node.size(); i++)
    {
        cout << i << "\t\t";
        for (int j = 0; j < node[i].a[0].size(); j++)
            cout << node[i].a[0][j] << ' ';
        cout << "\t\t";

        for (int j = 0; j < node[i].a[1].size(); j++)
            cout << node[i].a[1][j] << ' ';
        cout << "\t\t";

        for (int j = 0; j < node[i].eps.size(); j++)
            cout << node[i].eps[j] << ' ';
        cout << "\t\t";

        if (node[i].f)
            cout << "Yes";
        else
            cout << "No";
        cout << "\t\n";
    }
    cout << "-------------------------------------------------------------------------" << endl;
}

void re2Nfa(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case 'a':
        case 'b':
            alphabet(s[i] - 'a');
            break;
        case '*':
            closure();
            break;
        case '.':
            and_();
            break;
        case '+':
            or_();
            break;
        }
    }
}

int main()
{
    string RE;
    cout << "Enter a regular expression " << endl;
    cin >> RE;
    string postfix = infixToPostfix(RE);
    cout << endl
         << "The postfix notation is: " << postfix << endl;
    re2Nfa(postfix);
    int final_state = node_stk.top();
    node_stk.pop();
    int start_state = node_stk.top();
    node_stk.pop();

    node[final_state].f = 1;
    display_nfa();

    return 0;
}