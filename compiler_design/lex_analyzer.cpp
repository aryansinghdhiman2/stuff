#include <unordered_set>
#include <string>
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
string empty_str = "";
unordered_set<string> tokens;

const array<string,34> keywords = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
const array<char,9> delimiters = {' ',',',';','{','}','[',']','(',')'};
const array<char,12> operators = {'+','-','*','/','%','=','<','>','!','&','|','^'};
const array<string,19> combined_operators = {"++","--","+=","-=","*=","/=","%=","&=","|=","^=",">>","<<","==","!=","<=",">=","&&","||"};

//"<<=",">>="

bool isKeyword(const string& token)
{
    if(find(keywords.begin(),keywords.end(),token) != keywords.end())
    {
        return true;
    }
    else return false;
}

bool isDelimiter(const char& token)
{
    if(find(delimiters.begin(),delimiters.end(),token) != delimiters.end())
    {
        return true;
    }
    else return false;
}

bool isOperator(const char& token)
{
    if(find(operators.begin(),operators.end(),token) != operators.end())
    {
        return true;
    }
    else return false;
}

bool isCombinedOperator(const string& token)
{
    if(find(combined_operators.begin(),combined_operators.end(),token) != combined_operators.end())
    {
        return true;
    }
    else return false;
}

string::iterator processMacro(string::iterator current,const string::iterator& end,string token)
{
    if(current>=end) return current;
    string compare_str;

    switch (*current)
    {
    case 'i':
        compare_str.resize(7);
        copy(current,next(current,7),compare_str.begin());
        if(compare_str=="include")
        {
            tokens.insert("#include");
            return next(current,7);
        }
        // else
        // {
        //     token = "";
        //     return current+8;
        // }
        break;
    case 'd':
        compare_str.resize(6);
        copy(current,next(current,6),compare_str.begin());
        if(compare_str=="define")
        {
            tokens.insert("#define");
            return next(current,6);
        }
        break;
    default:
        break;
    }

    return next(current);
}

string::iterator processPlus(string::iterator current,const string::iterator& end,string token)
{
    if(current >= end)
    {
        tokens.insert(token);
        return current;
    }

    switch (*current)
    {
    case '+':
        tokens.insert("++");
        return next(current);
        break;
    case '-':
        tokens.insert("--");
        return next(current);
        break;
    default:
        tokens.insert(token);
        return current;
        break;
    }
}

string::iterator processTokens(string line)
{
    auto current = line.begin();
    string token = "";
    
    while(distance(current,line.end()) > 0)
    {
        if(isDelimiter(*current))
        {
            if(*current != ' ')
            {
                tokens.emplace(1,*current);
            }
            current = next(current);
            continue;
        }

        if(isOperator(*current))
        {
            const char op = *current;
            current = next(current);

            if(distance(current,line.end())<=0)
            {
                tokens.emplace(1,op);
                return current;
            }

            const string combined = string(1,op) + (*current);
            if(isCombinedOperator(combined))
            {
                tokens.insert(combined);
                current = next(current);
                continue;
            }
            else
            {
                tokens.emplace(1,op);
                continue;
            }
        }
    }
    return next(current);
}

int main()
{
    string s = "+; +";
    // processTokens(s.begin(),s.end(),empty_str);
    processTokens(s);
    for(auto token: tokens)
    {
        cout<<token<<'\n';
    }
}

    // switch (*current)
    // {
    // case ' ':
    //     current = processTokens(next(current),end,empty_str);
    //     break;
    // case '#':
    //     current = processMacro(next(current),end,token);
    //     processTokens(current,end,empty_str);
    //     break;
    // default:
    //     break;
    // }