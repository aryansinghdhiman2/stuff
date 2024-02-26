#ifndef __AUTOMATA__HPP__

#define __AUTOMATA__HPP__

#include <stack>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>
#include <list>
#include <stack>
#include <unordered_set>
#include "tabulate.hpp"

using string = std::string;

struct State;
struct Automata;
struct CompareStateLess;
struct HashState;
struct CompareStateEqual;

const char epsilon = '#';
int id_counter = -1;

// typedef std::list<std::weak_ptr<State>> transitionList;
typedef std::unordered_set<std::weak_ptr<State>,HashState,CompareStateEqual> transitionSet;

struct CompareStateLess
{
    bool operator()(const std::weak_ptr<State> a,const std::weak_ptr<State> b) const;
};

auto compare_state_less = CompareStateLess();

struct CompareStateEqual
{
    bool operator()(const std::weak_ptr<State> a,const std::weak_ptr<State> b) const;
};

struct HashState
{
    size_t operator()(const std::weak_ptr<State>& s) const;
};

struct State
{
    int id;
    bool is_accepting;
    std::unordered_map<char,transitionSet> transitions;
    State(int identifer,bool accept = false): id(identifer),is_accepting(accept){} 

    void insertTransition(char alphabet,const std::shared_ptr<State>& s)
    {
        if(this->transitions.find(alphabet) == this->transitions.end())
        {
            transitionSet l;
            l.insert(std::weak_ptr(s));
            this->transitions.insert(make_pair(alphabet,l));
        }
        else
        {
            this->transitions.at(alphabet).insert(std::weak_ptr(s));
        }
    }
    bool operator<(const State& other)
    {
        return this->id < other.id;
    }
    bool operator==(const State& other)
    {
        return this->id == other.id;
    }
};

struct Automata
{
    std::shared_ptr<State> initial_state;
    std::shared_ptr<State> final_state;
    std::list<std::shared_ptr<State>> states;

    Automata(){}
    Automata(char tran)
    {
        this->initial_state = std::make_shared<State>(++id_counter);
        this->final_state = std::make_shared<State>(++id_counter);
        this->initial_state->insertTransition(tran,final_state);
        this->states.push_back(initial_state);
        this->states.push_back(final_state);
    }
    Automata(const Automata& other)
    {
        this->initial_state = other.initial_state;
        this->final_state = other.final_state;
        this->states = other.states;
    }
};



bool CompareStateLess::operator()(const std::weak_ptr<State> a,const std::weak_ptr<State> b) const
{
    return (*(std::shared_ptr<State>)a) < *((std::shared_ptr<State>)b);  
}

bool CompareStateEqual::operator()(const std::weak_ptr<State> a,const std::weak_ptr<State> b) const
{
    return (*(std::shared_ptr<State>)a) == *((std::shared_ptr<State>)b);  
}

size_t HashState::operator()(const std::weak_ptr<State>& s) const
{
    return std::hash<int>()(std::shared_ptr<State>(s)->id);
}

Automata concatenation(Automata& first,Automata& second)
{
    Automata result(first);

    result.final_state->insertTransition(epsilon,second.initial_state);
    result.final_state = second.final_state;
    result.states.merge(second.states,compare_state_less);
    
    return result;
}

Automata _union(Automata& first,Automata& second)
{
    Automata result;

    result.initial_state = std::make_shared<State>(++id_counter);
    result.initial_state->insertTransition(epsilon,first.initial_state);
    result.initial_state->insertTransition(epsilon,second.initial_state);

    result.final_state = std::make_shared<State>(++id_counter);
    first.final_state->insertTransition(epsilon,result.final_state);
    second.final_state->insertTransition(epsilon,result.final_state);

    result.states.push_back(result.initial_state);
    result.states.push_back(result.final_state);

    result.states.merge(first.states,compare_state_less);
    result.states.merge(second.states,compare_state_less);

    return result;
}

Automata closure(Automata& first)
{
    Automata result;

    result.initial_state = std::make_shared<State>(++id_counter);
    result.final_state = std::make_shared<State>(++id_counter);

    result.initial_state->insertTransition(epsilon,result.final_state);
    result.initial_state->insertTransition(epsilon,first.initial_state);

    first.final_state->insertTransition(epsilon,result.final_state);
    first.final_state->insertTransition(epsilon,first.initial_state);

    result.states.push_back(result.initial_state);
    result.states.push_back(result.final_state);
    
    result.states.merge(first.states,compare_state_less);

    return result;
}

Automata processRegEx(const string& exp)
{
    std::stack<Automata> s;
    for(const char& alphabet : exp)
    {
        if(alphabet == '*')
        {
            Automata a = s.top();
            s.pop();
            a = closure(a);
            s.push(a);
        }
        else if(alphabet == '.')
        {
            Automata second  = s.top();
            s.pop();
            Automata first = s.top();
            s.pop();

            s.push(concatenation(first,second));
        }
        else if(alphabet == '|')
        {
            Automata second  = s.top();
            s.pop();
            Automata first = s.top();
            s.pop();

            s.push(_union(first,second));
        }
        else
        {
            s.emplace(alphabet);
        }
    }
    s.top().final_state->is_accepting = true;
    return s.top();
}

void closureTraversal(const std::shared_ptr<State>& s,transitionSet& states)
{
    states.insert(s);

    if(s->transitions.count(epsilon)==0)
    {
        return;
    }

    for(const auto& state : s->transitions.at(epsilon))
    {
        if(states.count(state)==0)
        {
            closureTraversal(std::shared_ptr<State>(state),states);
        }
    }

    return;
}

transitionSet epsilonClosure(const std::shared_ptr<State>& s)
{
    transitionSet states;
    closureTraversal(s,states);
    return states;
}

transitionSet epsilonClosure(const transitionSet& s)
{
    transitionSet states;
    for(const auto& state : s)
    {
        closureTraversal(std::shared_ptr<State>(state),states);
    }
    return states;
}

transitionSet move(const transitionSet& s,const char& alphabet)
{
    transitionSet states;
    for(const auto& state : s)
    {
        auto shared_state = std::shared_ptr<State>(state);
        if(shared_state->transitions.count(alphabet)!=0)
        {
            states.insert(shared_state->transitions.at(alphabet).begin(),shared_state->transitions.at(alphabet).end());
        }
    }
    return states;
}



void printAutomata(const Automata& input,std::vector<char> alphabets)
{
    tabulate::Table table;
    using Row_t = tabulate::Table::Row_t;
    Row_t header;
    header.push_back("State");
    for(const char& c : alphabets)
    {
        header.push_back(string(1,c));
    }

    table.add_row(header);
 
    size_t start_idx;
    std::vector<size_t> final_idx;
    for(auto state = input.states.begin();state!=input.states.end();state++)
    {
        const string id = std::to_string(state->get()->id);
        Row_t row;
        row.resize(alphabets.size()+1);

        for(const auto& neighbours : state->get()->transitions)
        {
            string row_str;
            for(const auto& neighbour : neighbours.second)
            {
                row_str += std::to_string(std::shared_ptr(neighbour)->id) + ",";
            }
            auto itr = find(alphabets.cbegin(),alphabets.cend(),neighbours.first);
            if(itr == alphabets.end())
            {
                throw string("Illegal Character");
            }
            else
            {
                ptrdiff_t k = std::distance(alphabets.cbegin(),itr);
                k+=1;
                row.at(k) = row_str;
            }
        }

        
        if((*state) == input.initial_state)
        {
            row.at(0) = "->"+id;
            table.add_row(row);
            start_idx = table.size()-1;
        }
        else
        {
            row.at(0) = id;
            table.add_row(row);
        }

        if(state->get()->is_accepting)
        {
            final_idx.push_back(table.size()-1);
        }
    }

    for(auto& r : table)
    {
        r.format().border_top("").border_bottom("").corner("");
    }
    table.row(0).format().show_border().border_top("-").corner("-");
    table.row(1).format().border_top("-").corner("-");
    table.row(table.size()-1).format().border_bottom("-").corner_bottom_left("-").corner_bottom_right("-");
    table.column(0).format().font_align(tabulate::FontAlign::right);
    table.row(start_idx).cell(0).format().font_background_color(tabulate::Color::blue);

    for(auto index : final_idx)
    {
        table.row(index).cell(0).format().font_background_color(tabulate::Color::green);
    }

    std::cout<<table<<std::endl;
}


#endif