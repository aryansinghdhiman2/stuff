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
#include <set>
#include <queue>
#include <optional>
#include <array>
#include <cstdlib>
#include "tabulate.hpp"

using string = std::string;

struct State;
struct Automata;
struct CompareStateLess;
struct HashState;
struct CompareStateEqual;

const char epsilon = '#';
int id_counter = -1;

using StateSharedPointer = std::shared_ptr<State>;
using StateWeakPointer = std::weak_ptr<State>;
using TransitionSet = std::unordered_set<StateWeakPointer,HashState,CompareStateEqual>;
using TransitionSetShared = std::unordered_set<StateSharedPointer,HashState,CompareStateEqual>;

/**
 * A function Object used to compare two states of the automata.
 * 
 * Acts as Less Than
 */
struct CompareStateLess
{
    bool operator()(const StateWeakPointer a,const StateWeakPointer b) const;
};

// auto compare_state_less = CompareStateLess();

struct CompareStateEqual
{
    bool operator()(const StateWeakPointer a,const StateWeakPointer b) const;
};

struct HashState
{
    size_t operator()(const StateWeakPointer& s) const;
};

struct State
{
    int id;
    bool is_accepting;
    std::optional<std::string> combined_id;
    std::optional<TransitionSet> combined_set;
    std::unordered_map<char,TransitionSet> transitions;
    State(int identifer,bool accept = false): id(identifer),is_accepting(accept){} 

    void insertTransition(char alphabet,const StateSharedPointer& s)
    {
        if(this->transitions.find(alphabet) == this->transitions.end())
        {
            TransitionSet l;
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
        if(this->combined_id and other.combined_id)
        {
            return (this->combined_id.value() == other.combined_id.value()) or (this->id == other.id);

        }
        return this->id == other.id;
    }
};

struct Automata
{
    StateSharedPointer initial_state;
    StateSharedPointer final_state; //Only used with NFA
    std::set<StateSharedPointer,CompareStateLess> states;

    Automata(){}
    Automata(char tran)
    {
        this->initial_state = std::make_shared<State>(++id_counter);
        this->final_state = std::make_shared<State>(++id_counter);
        this->initial_state->insertTransition(tran,final_state);
        this->states.insert(initial_state);
        this->states.insert(final_state);
    }
    Automata(const Automata& other)
    {
        this->initial_state = other.initial_state;
        this->final_state = other.final_state;
        this->states = other.states;
    }
};



bool CompareStateLess::operator()(const StateWeakPointer a,const StateWeakPointer b) const
{
    return (*(StateSharedPointer)a) < *((StateSharedPointer)b);  
}

bool CompareStateEqual::operator()(const StateWeakPointer a,const StateWeakPointer b) const
{
    return (*(StateSharedPointer)a) == *((StateSharedPointer)b);  
}

size_t HashState::operator()(const StateWeakPointer& s) const
{
    StateSharedPointer sh = StateSharedPointer(s);
    if(sh->combined_id)
    {
        return std::hash<std::string>()(sh->combined_id.value());
    }
    return std::hash<int>()(sh->id);
}

Automata concatenation(Automata& first,Automata& second)
{
    Automata result(first);

    result.final_state->insertTransition(epsilon,second.initial_state);
    result.final_state = second.final_state;
    result.states.merge(second.states);
    
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

    result.states.insert(result.initial_state);
    result.states.insert(result.final_state);

    result.states.merge(first.states);
    result.states.merge(second.states);

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

    result.states.insert(result.initial_state);
    result.states.insert(result.final_state);
    
    result.states.merge(first.states);

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

void closureTraversal(const StateSharedPointer& s,TransitionSet& states)
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
            closureTraversal(StateSharedPointer(state),states);
        }
    }

    return;
}

TransitionSet epsilonClosure(const StateSharedPointer& s)
{
    TransitionSet states;
    closureTraversal(s,states);
    return states;
}

TransitionSet epsilonClosure(const TransitionSet& s)
{
    TransitionSet states;
    for(const auto& state : s)
    {
        closureTraversal(StateSharedPointer(state),states);
    }
    return states;
}

TransitionSet move(const StateSharedPointer& s,const char& alphabet)
{
    if(s->transitions.count(alphabet)!=0)
    {
        return s->transitions.at(alphabet);
    }
    else return TransitionSet();
}

TransitionSet move(const TransitionSet& s,const char& alphabet)
{
    TransitionSet states;
    for(const auto& state : s)
    {
        auto shared_state = StateSharedPointer(state);
        if(shared_state->transitions.count(alphabet)!=0)
        {
            states.insert(shared_state->transitions.at(alphabet).begin(),shared_state->transitions.at(alphabet).end());
        }
    }
    return states;
}

std::optional<std::string> makeCombinedId(TransitionSet s)
{
    std::string combined_id_str;
    std::vector<int> id_arr;
    id_arr.reserve(s.size());

    for(const auto& state : s)
    {
        id_arr.push_back(StateSharedPointer(state)->id);
    }

    std::sort(id_arr.begin(),id_arr.end());

    for(const auto& id : id_arr)
    {
        combined_id_str += std::to_string(id) + ',';
    }

    return std::make_optional(combined_id_str);
}

Automata convertToDFA(const StateSharedPointer& nfa_start_state,const std::vector<char> alphabets)
{
    Automata dfa;
    dfa.initial_state = std::make_shared<State>(*nfa_start_state);
    dfa.initial_state->id = ++id_counter;

    TransitionSetShared states;
    states.insert(dfa.initial_state);

    std::queue<StateSharedPointer> q;
    q.push(dfa.initial_state);

    while(not q.empty())
    {
        StateSharedPointer current_state = q.front();
        q.pop();

        TransitionSet closure_set;
        if(current_state->combined_set)
        {
            closure_set = epsilonClosure(current_state->combined_set.value());
        }
        else
        {
            closure_set = epsilonClosure(current_state);
        }

        auto accepting_itr = std::find_if(closure_set.begin(),closure_set.end(),[](const StateWeakPointer& s){
            if(StateSharedPointer(s)->is_accepting)
            {
                return true;
            }
            else return false;
        });

        if(accepting_itr!=closure_set.end())
        {
            current_state->is_accepting = true;
        }

        for(size_t i=0;i<alphabets.size();i++)
        {
            TransitionSet result_set = epsilonClosure(move(closure_set,alphabets.at(i)));   
            
            if(result_set.empty()) continue;

            StateSharedPointer combined_state = std::make_shared<State>(++id_counter);
            combined_state->combined_id = makeCombinedId(result_set);
            combined_state->combined_set = std::make_optional(result_set);            

            if(auto state_itr = states.find(combined_state); state_itr!=states.end())
            {
                combined_state = StateSharedPointer(*state_itr);
                --id_counter;
            }

            if(current_state == dfa.initial_state)
            {
                current_state->transitions.erase(alphabets.at(i));
            }
            current_state->insertTransition(alphabets.at(i),combined_state);

            if(states.insert(combined_state).second)
            {
                q.push(combined_state);
            }
        }

        if(current_state == dfa.initial_state)
        {
            current_state->transitions.erase(epsilon);
        }
    }

    dfa.states.insert(states.begin(),states.end());
    return dfa;
}

void printAutomata(const Automata& input,const std::vector<char>& alphabets)
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
                std::cout<<"Illegal Character\n";
                std::abort();
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

    for(auto index : final_idx)
    {
        table.row(index).cell(0).format().font_background_color(tabulate::Color::green);
    }

    table.row(start_idx).cell(0).format().font_color(tabulate::Color::red);
    
    std::cout<<table<<'\n';
}


#endif