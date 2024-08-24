#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

vector<char> nonTerminals = {'E', 'X', 'T', 'Y', 'F'};

vector<char> terminals = {'a', '(', ')', '+', '*', '$'};

unordered_map<char, unordered_map<char, string>> table;

void creatingtable(unordered_map<char, unordered_map<char, string>> &table)
{
    table['E']['a'] = "TX";
    table['E']['('] = "TX";
    table['X']['+'] = "+TX";
    table['X'][')'] = "e";
    table['X']['$'] = "e";
    table['T']['a'] = "FY";
    table['T']['('] = "FY";
    table['Y']['+'] = "e";
    table['Y']['*'] = "*FY";
    table['Y'][')'] = "e";
    table['Y']['$'] = "e";
    table['F']['a'] = "a";
    table['F']['('] = "(E)";
}

bool predictiveParser(string input, char startSymbol, unordered_map<char, unordered_map<char, string>> &table)
{
    input = input + "$";
    stack<char> st;
    st.push('$');
    st.push(startSymbol);
    int i = 0;
    char stTop, ch;
    while (st.top() != '$')
    {
        ch = input[i];
        if (st.top() != '$')
        {
            stTop = st.top();
            st.pop();
        }
        cout << stTop << " " << ch << endl;
        if (find(nonTerminals.begin(), nonTerminals.end(), stTop) != nonTerminals.end())
        {
            if (table.count(stTop) && table[stTop].count(ch))
            {
                cout << "In Comparsion  " << stTop << " " << ch << endl;
                string temp = table[stTop][ch];
                reverse(temp.begin(), temp.end());
                for (auto ele : temp)
                {
                    if (ele == 'e')
                    {
                        continue;
                    }
                    st.push(ele);
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            cout << "inc i pointer" << endl;
            i++;
        }
    }
    if (input[i] == '$' && st.top() == '$')
    {
        cout << "end condition" << endl;
        return true;
    }

    return false;
}

int main()
{
    vector<string> grammer;
    string input, temp;
    input = "a+a*a";
    grammer = {"E=TX", "X=+TX", "X=e", "T=FY", "Y=*FY", "Y=e", "F=(E)", "F=a"};
    // cout << "Enter the input string: ";
    // cin >> input;

    creatingtable(table);
    bool ans = predictiveParser(input, 'E', table);
    cout << "Result: " << ans << endl;

    return 0;
}