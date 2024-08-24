#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>
#include <unordered_set>
#include <iomanip>

using namespace std;

int totalStates = 1;

class NFA
{
public:
    int initalState;
    int finalState;
    vector<pair<int, pair<char, int>>> transitions;
};

int prec(char ch)
{
    // Function to return precedence of operators
    if (ch == '*')
        return 3;
    else if (ch == '.')
        return 2;
    else if (ch == '|')
        return 1;
    else
        return -1;
}

string toPostFixNotation(string &str)
{
    // Function to convert infix to post fix notation
    stack<char> st;
    string result;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        // If the scanned character is an operand, add it to the output string.
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            result += ch;
        // If the scanned character is an ‘(‘, push it to the stack.
        else if (ch == '(')
            st.push('(');
        // If the scanned character is an ‘)’, pop and add to the output string from the stack until an ‘(‘ is encountered.
        else if (ch == ')')
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
            while (!st.empty() && prec(str[i]) < prec(st.top()) ||
                   !st.empty() && prec(str[i]) == prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}

bool isSymbol(char ch)
{
    vector<char> symbol = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                           'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                           't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D',
                           'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
                           'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                           '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    auto it = find(symbol.begin(), symbol.end(), ch);
    if (it != symbol.end())
    {
        return true;
    }
    return false;
}

NFA closureOperator(NFA nfa1)
{
    // Function to Calculate the Kleen CLosure of given NFA
    // Create a new NFA
    NFA result;
    // Adding all the previous transitions of NFA into new NFA
    for (int i = 0; i < nfa1.transitions.size(); i++)
    {
        result.transitions.push_back(nfa1.transitions[i]);
    }
    // Adding 'E' transitions into the new NFA
    result.initalState = totalStates++;
    result.finalState = totalStates++;
    result.transitions.push_back({result.initalState, {'E', nfa1.initalState}});
    result.transitions.push_back({nfa1.finalState, {'E', result.finalState}});
    result.transitions.push_back({result.initalState, {'E', result.finalState}});
    result.transitions.push_back({nfa1.finalState, {'E', nfa1.initalState}});

    return result;
}

NFA concatenationOperator(NFA nfa1, NFA nfa2)
{
    // Function to concatenate two NFA's
    // Creating a new NFA
    NFA result;
    // Adding the previous transitions of NFA into new NFA
    for (int i = 0; i < nfa1.transitions.size(); i++)
    {
        result.transitions.push_back(nfa1.transitions[i]);
    }
    for (int i = 0; i < nfa2.transitions.size(); i++)
    {
        result.transitions.push_back(nfa2.transitions[i]);
    }
    // Adding 'E' transitions to new NFA
    result.initalState = totalStates++;
    result.finalState = totalStates++;
    result.transitions.push_back({result.initalState, {'E', nfa1.initalState}});
    result.transitions.push_back({nfa1.finalState, {'E', nfa2.initalState}});
    result.transitions.push_back({nfa2.finalState, {'E', result.finalState}});

    return result;
}

NFA unionOperator(NFA nfa1, NFA nfa2)
{
    // Function to calculate the union of two NFA's
    // Creating a new NFA
    NFA result;
    // Adding the transitions of previous NFA's to new NFA
    for (int i = 0; i < nfa1.transitions.size(); i++)
    {
        result.transitions.push_back(nfa1.transitions[i]);
    }
    for (int i = 0; i < nfa2.transitions.size(); i++)
    {
        result.transitions.push_back(nfa2.transitions[i]);
    }
    // Adding 'E' transitions to new NFA
    result.initalState = totalStates++;
    result.finalState = totalStates++;
    result.transitions.push_back({result.initalState, {'E', nfa1.initalState}});
    result.transitions.push_back({result.initalState, {'E', nfa2.initalState}});
    result.transitions.push_back({nfa1.finalState, {'E', result.finalState}});
    result.transitions.push_back({nfa2.finalState, {'E', result.finalState}});

    return result;
}

vector<int> eClosureCalculation(int state, set<int> &closure, vector<unordered_map<char, vector<int>>> &NFATable)
{
    // Function to Caluclate the E-Closure of a given state.
    vector<int> eStates = NFATable[state]['E'];
    for (auto state : eStates)
    {
        closure.insert(state);
    }
    return eStates;
}

set<int> DFAstates(set<int> states, char symbol, map<int, set<int>> &closureTable, vector<unordered_map<char, vector<int>>> &NFATable)
{
    // To calculate the e-closure of a given state on a given symbol
    vector<int> intermediate;
    for (auto element : states)
    {
        // Calculate transition function of each state on each input symbol
        vector<int> temp = NFATable[element][symbol];
        if (temp.size() > 0)
        {
            for (auto i : temp)
            {
                intermediate.push_back(i);
            }
        }
    }
    set<int> ans;
    for (auto ele : intermediate)
    {
        // Calculating the E - closure of states given by the transition function
        set<int> temp = closureTable[ele];
        if (temp.size() > 0)
        {
            for (auto i : temp)
            {
                ans.insert(i);
            }
        }
    }
    return ans;
}

string setToString(set<int> s)
{
    // Used as a print function
    string t = "{ ";
    for (auto i : s)
    {
        t = t + to_string(i) + " ";
    }
    t = t + "}";
    return t;
}

int main()
{
    string regExpression;
    cout << "Enter the regular expression where (*, Closure), (|,Union), (., Concatenation): ";
    cin >> regExpression;

    // Conversion of given regular expression from infix notation to post fix notation
    string expression = toPostFixNotation(regExpression);

    cout << endl
         << "Postfix form of Regular Expression:   " << expression;
    cout << endl;

    stack<NFA> s;
    set<char> symbols;

    // Reading the given expression from left to right
    int i = 0;
    while (i < expression.length())
    {
        if (isSymbol(expression[i]))
        {
            // Creating a new NFA of a given symbol
            NFA newNFA;
            newNFA.initalState = totalStates++;
            newNFA.finalState = totalStates++;
            newNFA.transitions.push_back({newNFA.initalState, {expression[i], newNFA.finalState}});
            s.push(newNFA);
            symbols.insert(expression[i]);
        }
        else if (expression[i] == '*')
        {
            // pop the top most element of the stack
            // perform closure operation on the top element
            NFA newNFA = closureOperator(s.top());
            s.pop();
            // push back the top element
            s.push(newNFA);
        }
        else if (expression[i] == '.')
        {
            // pop the top 2 elements of the stack
            NFA nfa1 = s.top();
            s.pop();
            NFA nfa2 = s.top();
            s.pop();
            // perform concatenation operation on the elements
            NFA newNFA = concatenationOperator(nfa2, nfa1);
            // push back the element on the top of stack
            s.push(newNFA);
        }
        else if (expression[i] == '|')
        {
            // pop the top 2 elements of the stack
            NFA nfa1 = s.top();
            s.pop();
            NFA nfa2 = s.top();
            s.pop();
            // perform union operation on the elements
            NFA newNFA = unionOperator(nfa2, nfa1);
            // push back the element on the top of stack
            s.push(newNFA);
        }
        else
        {
            cout << "Invalid Input !!!" << endl;
            exit(1);
        }
        i = i + 1;
    }

    symbols.insert('E');
    // Resultant NFA
    NFA ans = s.top();
    s.pop();

    vector<unordered_map<char, vector<int>>> table(ans.finalState + 1);
    // Storing the resultant NFA in tabular Format
    for (auto transition : ans.transitions)
    {
        int state = transition.first;
        char inputSymbol = transition.second.first;
        int transitionState = transition.second.second;
        table[state][inputSymbol].push_back(transitionState);
    }

    cout << endl
         << "*****Transition Table of NFA with E-moves*****" << endl;
    // Printing the table
    cout << "Inital State:   " << ans.initalState << endl;
    cout << "Final State:    " << ans.finalState << endl;
    cout << "|" << setw(10) << "States"
         << "|";
    for (auto i : symbols)
    {
        cout << setw(10) << i << "|";
    }
    cout << endl;

    for (int i = 1; i <= ans.finalState; i++)
    {
        cout << "|" << setw(10) << i << "|";
        for (auto j : symbols)
        {
            if (table[i][j].size() > 0)
            {
                int count = 0;
                string t = "";
                for (int k = 0; k < table[i][j].size(); k++)
                {
                    t = t + " " + to_string(table[i][j][k]);
                }
                cout << setw(10) << t << "|";
            }
            else
            {
                cout << setw(10) << "-"
                     << "|";
            }
        }
        cout << endl;
    }

    cout << endl
         << endl;

    // NFA--> DFA
    // Creating table of E-closure of all the states present in the NFA
    map<int, set<int>> closureTable;

    for (int i = 1; i <= ans.finalState; i++)
    {
        set<int> closure;
        closure.insert(i);
        vector<int> val = eClosureCalculation(i, closure, table);
        while (true)
        {
            if (val.size() > 0)
            {
                vector<int> temp;
                temp = val;
                val.clear();
                for (int j = 0; j < temp.size(); j++)
                {
                    vector<int> temp1 = eClosureCalculation(temp[j], closure, table);
                    if (temp1.size() > 0)
                    {
                        for (auto j : temp1)
                        {
                            val.push_back(j);
                        }
                    }
                }
            }
            else
            {
                break;
            }
        }
        closureTable[i] = closure;
    }

    // Calculating a DFA susing the closure Table and the NFA table
    queue<set<int>> states;
    states.push(closureTable[ans.initalState]);
    set<set<int>> states_DFA;
    states_DFA.insert(closureTable[ans.initalState]);

    // Converting symbol set to vector and poping epsilon symbol
    symbols.erase('E');
    vector<int> symbol(symbols.begin(), symbols.end());
    vector<set<int>> finalStates_DFA;
    if (closureTable[ans.initalState].find(ans.finalState) != closureTable[ans.initalState].end())
    {
        finalStates_DFA.push_back(closureTable[ans.initalState]);
    }
    cout << "*****Transition Table of DFA made from NFA with E-moves*****" << endl;

    cout << "|" << setw(29) << "States"
         << " |";
    for (auto sym : symbols)
    {
        cout << setw(30) << sym << "|";
    }
    cout << endl;
    vector<pair<set<int>, map<char, set<int>>>> DFATable;
    while (!states.empty())
    {
        cout << "|" << setw(30) << setToString(states.front()) << "|";
        map<char, set<int>> temp;
        for (int i = 0; i < symbol.size(); i++)
        {
            set<int> newState = DFAstates(states.front(), symbol[i], closureTable, table);
            if (find(states_DFA.begin(), states_DFA.end(), newState) == states_DFA.end() && newState.size() > 0)
            {
                states.push(newState);
                states_DFA.insert(newState);
                if (newState.find(ans.finalState) != newState.end())
                {
                    finalStates_DFA.push_back(newState);
                }
            }
            cout << setw(30) << setToString(newState) << "|";
            temp[symbol[i]] = newState;
        }
        DFATable.push_back({states.front(), temp});
        states.pop();
        cout << endl;
    }
    cout << "Inital State:   " << setToString(closureTable[ans.initalState]) << endl;
    cout << "Final State:    ";
    for (auto i : finalStates_DFA)
    {
        cout << setToString(i) << " ";
    }
    cout << endl;
    map<set<int>, char> DFAAlisa;
    int count = 0;
    for (auto ele : states_DFA)
    {
        DFAAlisa[ele] = 'A' + count;
        count++;
    }
    cout << endl
         << endl;

    cout << "*****Transition Table of DFA with alias names made from NFA with E-moves*****" << endl;

    cout << "|" << setw(8) << "States"
         << "|";

    for (auto sym : symbols)
    {
        cout << setw(5) << sym << "|";
    }
    cout << endl;

    for (auto p : DFATable)
    {
        cout << "|" << setw(8) << DFAAlisa[p.first] << "|";
        for (auto m : p.second)
        {
            if (m.second.empty())
            {
                cout << setw(5) << "-"
                     << "|";
            }
            else
            {
                cout << setw(5) << DFAAlisa[m.second] << "|";
            }
        }
        cout << endl;
    }
    cout << "Inital State:   " << DFAAlisa[closureTable[ans.initalState]] << endl;
    cout << "Final State:    ";
    for (auto i : finalStates_DFA)
    {
        cout << DFAAlisa[i] << " ";
    }
    cout << endl;
    return 0;
}
