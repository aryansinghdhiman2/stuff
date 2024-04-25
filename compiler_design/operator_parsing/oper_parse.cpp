#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
using namespace std;

const size_t num_op = 5;

using tableType = array<array<char,num_op>,num_op>;

tableType table;


enum operators {
    plus,
    minus,
    multiply,
    id,
    dollar
};

const array<string,num_op> OpToChar = {"+","-","*","id","$"};

void parse(const vector<operators> expression)
{
    stack<operators> s;
    s.push(operators::dollar);
    auto it = expression.begin();

    stack<operators> popped_symbols;
    popped_symbols.push(dollar);
    while(true)
    {
        if(s.top()==operators::dollar and *it == operators::dollar)
        {
            cout<<"Accept\n";
            return;
        }
        else
        {
            const operators& op1 = s.top();
            const operators& op2 = *it;

            switch (table.at(op1).at(op2))
            {
            case '>':
            {
                if(op1==operators::id)
                {
                    cout<<"Reduce by E -> id\n";
                }
                else
                {
                    auto popped = popped_symbols.top();
                    popped_symbols.pop();

                    if((popped_symbols.top()==operators::id) and (popped == operators::id))
                    {
                        cout<<"Reduce by E -> E "<<OpToChar.at(op1)<<" E\n";
                    }
                    else 
                    {
                        popped_symbols.push(popped);
                        cout<<"Error\n";
                        return;
                    }
                }
                if(s.top()==operators::id)
                {
                    popped_symbols.push(s.top());
                }
                s.pop();

                while(table.at(s.top()).at(popped_symbols.top()) != '<')
                {
                    s.pop();
                }
                break;
            }
            case '<':
            case '=':
            {
                cout<<"Shift\n";
                s.push(op2);
                it=it+1;
                break;
            }
            default:
            {
                cout<<"Error\n";
                return;
                break;
            }
            }
        }
    }

}

int main()
{
    //                                +   -   *   id  $     
    table.at(operators::plus) =     {'>','<','<','<','>'};
    table.at(operators::minus) =    {'>','>','<','<','>'};
    table.at(operators::multiply) = {'>','>','>','<','>'};
    table.at(operators::id) =       {'>','>','>',' ','>'};
    table.at(operators::dollar) =   {'<','<','<','<',' '};

    cout<<"Enter Expression: ";
    string exp;
    cin>>exp;
    vector<operators> tokens;
    for(const char& c : exp)
    {
        if(c == ' ')
        {
            continue;
        }
        else if(c == '+')
        {
            tokens.push_back(operators::plus);
        }
        else if(c == '-')
        {
            tokens.push_back(operators::minus);
        }
        else if(c == '*')
        {
            tokens.push_back(operators::multiply);
        }
        else
        {
            tokens.push_back(operators::id);
        }
    }

    tokens.push_back(operators::dollar);
    parse(tokens);
}