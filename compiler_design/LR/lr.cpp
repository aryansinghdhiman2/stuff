#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Rule
{
    char lhs;
    string rhs;
    Rule(char l,const string& r):lhs(l),rhs(r){}
    void print() const
    {
        cout<<this->lhs<<"->"<<this->rhs<<'\n';
    }
};

struct Item : public Rule
{
    size_t dot;
    Item(char l,const string& r):Rule(l,r)
    {
        this->dot = 0;
    }
    Item(const Rule& a):Rule(a)
    {
        this->dot = 0;
    }
    char get_symbol() const
    {
        return this->rhs.at(dot);
    }
    bool increment()
    {
        if(this->dot+1 >= this->rhs.size())
        {
            return false;
        }
        else
        {
            this->dot+=1;
            return true;
        }
    }
    void print() const
    {
        string dotted_rhs = this->rhs;
        dotted_rhs.insert(this->dot,".");
        cout<<this->lhs<<"->"<<dotted_rhs<<'\n';
    }
};

struct HashItem
{
    size_t operator()(const Item& i) const
    {
        return hash<char>()(i.lhs) ^ hash<string>()(i.rhs) ^ hash<size_t>()(i.dot);
    }
};

struct EqualItem
{
    bool operator()(const Item& a,const Item& b) const
    {
        return (a.lhs == b.lhs) && (a.rhs == b.rhs) && (a.dot == b.dot);
    }
};

struct Closure 
{
    unordered_set<Item,HashItem,EqualItem> items;
};

unordered_multimap<char,Rule> grammar;
unordered_set<char> terminals;
unordered_set<char> non_terminals;

Closure generate_closure(const Item& start_rule)
{
    Closure c;
    c.items.insert(start_rule);

    char alphabet = start_rule.get_symbol();
    queue<char> q;
    unordered_set<char> visited;

    q.push(alphabet);
    
    while(!q.empty())
    {
        const char symb = q.front();
        visited.insert(symb);
        q.pop();

        auto range = grammar.equal_range(symb);
        for(auto itr = range.first;itr!=range.second;itr++)
        {
            if(visited.count(itr->second.rhs.front())==0)
            {
                if(terminals.count(itr->second.rhs.front())==0)
                {
                    q.push(itr->second.rhs.front());
                }
                c.items.insert(itr->second);
            }
        }
    }

    return c;
}

Closure _goto(const Closure& c,char symbol)
{
    auto gItemItr = find_if(c.items.begin(),c.items.end(),[symbol](const Item& i){
        if(i.get_symbol()==symbol)
        {
            return true;
        }
        else return false;
    });

    if(gItemItr==c.items.end())
    {
        return Closure();
    }

    Item i = *gItemItr;
    if(i.increment())
    {
        return generate_closure(i);
    }
    else return Closure();
}

int main()
{
    grammar.insert({'Z',Rule('Z',"S")});
    grammar.insert({'S',Rule('S',"AA")});
    grammar.insert({'A',Rule('A',"aA")});
    grammar.insert({'A',Rule('A',"b")});

    cout<<"Grammar: \n";
    for(const auto& r : grammar)
    {
        r.second.print();
    }
    cout<<endl;

    terminals.insert('a');
    terminals.insert('b');

    non_terminals.insert('S');
    non_terminals.insert('A');

    Closure c = generate_closure(Item('Z',"S"));
    cout<<"Closure:\n";
    for(const Item& i : c.items)
    {
        i.print();
    }
    cout<<"\nGoto on A\n";
    c = _goto(c,'A');
    for(const Item& i : c.items)
    {
        i.print();
    }
    return 0;
}