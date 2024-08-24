#include <set>
#include <string>
#include <iostream>
#include <array>
#include <algorithm>
#include <cctype>
#include <fstream>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/hashed_index.hpp>

using namespace std;

struct lexeme
{
    string id;
    string type;
    int line_number;
    int seq_number;
    // size_t operator()(const lexeme& l) const noexcept
    // {
    //     return hash<string>()(l.id);
    // }
    // bool operator==(const lexeme& other) const
    // {
    //     return this->id == other.id;
    // }
    bool operator<(const lexeme& other) const
    {
        if(this->line_number < other.line_number)
        {
            return true;
        }
        else if(this->line_number == other.line_number and this->seq_number < other.seq_number)
        {
            return true;
        }
        else return false;
    }
};

using boost::multi_index::multi_index_container;
using boost::multi_index::indexed_by;
using boost::multi_index::ordered_unique;
using boost::multi_index::member;
using boost::multi_index::ordered_non_unique;
using boost::multi_index::identity;
using boost::multi_index::hashed_unique;

multi_index_container<
    lexeme,
    indexed_by<
            hashed_unique<member<lexeme,std::string,&lexeme::id>>,
            ordered_non_unique<identity<lexeme>>
    >
> tokens;

// set<lexeme> tokens;

const array<string,34> keywords = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
const array<char,9> delimiters = {',',';','{','}','[',']','(',')',' '};
const array<char,12> operators = {'+','-','*','/','%','=','<','>','!','&','|','^'};
const array<string,19> combined_operators = {"++","--","+=","-=","*=","/=","%=","&=","|=","^=",">>","<<","==","!=","<=",">=","&&","||"};
const array<string,13> directives = {"#include", "#pragma", "#define", "#error", "#warning", "#undef", "#if", "#else", "#elif", "#endif", "#ifdef", "#ifndef", "#line"};

bool isKeyword(const string& token)
{
    if(find(keywords.begin(),keywords.end(),token) != keywords.end())
    {
        return true;
    }
    else return false;
}

bool isDirective(const string& token)
{
    if(find(directives.begin(),directives.end(),token) != directives.end())
    {
        return true;
    }
    else return false;
}

bool isDelimiter(char token)
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

void processTokens(const string line,const int line_number)
{
    auto current = line.begin();
    int seq = 0;
    while(distance(current,line.end()) > 0)
    {
        lexeme token;
        token.line_number = line_number;
        token.seq_number = ++seq;

        if(isDelimiter(*current))
        {
            if(*current != ' ')
            {
                token.id = string(1,*current);
                token.type = "Delimeter";
                tokens.insert(token);
            }
            current = next(current);
        }
        else if(*current == '"')
        {
            auto literal_end = find(next(current),line.end(),'"');
            if(literal_end == line.end())
            {
                throw "Literal Not Ending"s;
            }

            token.type = "String Literal";
            literal_end = next(literal_end);
            token.id.resize(distance(current,literal_end));
            copy(current,literal_end,token.id.begin());
            tokens.insert(token);

            current = literal_end;
        }
        else if(isdigit(*current))
        {
            int (*is_digit)(int) = &isdigit;
            auto literal_end = find_if_not(next(current),line.end(),is_digit);

            if(isalpha(*literal_end))
            {
                throw "Invalid Numeric Literal"s;
            }

            token.type = "Numeric Literal";
            token.id.resize(distance(current,literal_end));
            copy(current,literal_end,token.id.begin());
            tokens.insert(token);
            current = next(literal_end);
        }
        else if(isOperator(*current))
        {
            const char op = *current;
            current = next(current);

            if(op == '/' and current != line.end() and (*current) == '/')
            {
                current = line.end();
                continue;
            }
            
            token.type = "Operator";
            if(distance(current,line.end())<=0)
            {
                token.id = string(1,op);
                tokens.insert(token);
                return;
            }

            const string combined = string(1,op) + (*current);
            if(isCombinedOperator(combined))
            {
                token.id = combined;
                tokens.insert(token);
                current = next(current);
            }
            else
            {
                token.id = string(1,op);
                tokens.insert(token);
            }
        }
        else if(*current == '#')
        {
            auto directive_end = find(current,line.end(),' ');

            token.id.resize(distance(current,directive_end));
            copy(current,directive_end,token.id.begin());

            if(not isDirective(token.id))
            {
                throw "Not a valid directive"s;
            }

            token.type = "Directive";

            tokens.insert(token);

            if(directive_end != line.end() and next(directive_end) != line.end())
            {
                token.id.clear();
                token.type.clear();

                token.id.insert(token.id.begin(),next(directive_end),line.end());
                token.type = "Macro";

                tokens.insert(token);

                current = line.end();
            }
            else current = directive_end;
        }
        else if(isalpha(*current) or (*current == '_'))
        {
            auto end = find_if(current,line.end(),isDelimiter);
            
            token.id.resize(distance(current,end));
            copy(current,end,token.id.begin());
            if(isKeyword(token.id))
            {
                token.type = "Keyword";
            }
            else 
            {
                token.type = "Identifier";
            }
            tokens.insert(token);
            current = end;
        }
    }
}

int main()
{

    ifstream file("t1.c");

    if(file.is_open())
    {
        string line;
        int line_number = 0;
        while(getline(file,line))
        {
            ++line_number;
            processTokens(line,line_number);
        }
        file.close();

        for(auto token: tokens.get<1>())
        {
            cout<<token.type<<'\t'<<token.id<<'\n';
        }
    }
    else cout<<"File Error";
}