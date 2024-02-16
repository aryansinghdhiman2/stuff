#include <stack>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>
#include <list>
#include <stack>
#include "parse.h"

using namespace std;

char epsilon = '#';
int id_counter = 0;

struct State;
struct Automata;

typedef list<weak_ptr<State>> transitionList;

struct State
{
    int id;
    bool is_accepting;
    unordered_map<char,transitionList> transitions;
    State(int identifer,bool accept = false): id(identifer),is_accepting(accept){} 

    void insertTransition(char alphabet,const shared_ptr<State>& s)
    {
        if(this->transitions.find(alphabet) == this->transitions.end())
        {
            transitionList l;
            l.push_back(weak_ptr(s));
            this->transitions.insert(make_pair(alphabet,l));
        }
        else
        {
            this->transitions.at(alphabet).push_back(weak_ptr(s));
        }
    }
};

struct Automata
{
    shared_ptr<State> initial_state;
    shared_ptr<State> final_state;
    list<shared_ptr<State>> states;

    Automata(){}
    Automata(char tran)
    {
        this->initial_state = make_shared<State>(++id_counter);
        this->final_state = make_shared<State>(++id_counter);
        this->initial_state->insertTransition(tran,final_state);
        this->states.push_back(initial_state);
        this->states.push_back(final_state);
    }
};

Automata concatenation(Automata& first,Automata& second)
{
    Automata result;
    
    result.initial_state = make_shared<State>(++id_counter);
    result.initial_state->insertTransition(epsilon,first.initial_state);

    first.final_state->insertTransition(epsilon,second.initial_state);
    
    result.final_state = make_shared<State>(++id_counter);
    second.final_state->insertTransition(epsilon,result.final_state);

    result.states.push_back(result.initial_state);
    result.states.push_back(result.final_state);

    result.states.merge(first.states);
    result.states.merge(second.states);

    return result;
}



Automata _union(Automata& first,Automata& second)
{
    Automata result;

    result.initial_state = make_shared<State>(++id_counter);
    result.initial_state->insertTransition(epsilon,first.initial_state);
    result.initial_state->insertTransition(epsilon,second.initial_state);

    result.final_state = make_shared<State>(++id_counter);
    first.final_state->insertTransition(epsilon,result.final_state);
    second.final_state->insertTransition(epsilon,result.final_state);

    result.states.push_back(result.initial_state);
    result.states.push_back(result.final_state);

    result.states.merge(first.states);
    result.states.merge(second.states);

    return result;
}

Automata closure(Automata& first)
{
    Automata result;

    result.initial_state = make_shared<State>(++id_counter);
    result.final_state = make_shared<State>(++id_counter);

    result.initial_state->insertTransition(epsilon,result.final_state);
    result.initial_state->insertTransition(epsilon,first.initial_state);

    first.final_state->insertTransition(epsilon,result.final_state);
    first.final_state->insertTransition(epsilon,first.initial_state);

    result.states.push_back(result.initial_state);
    result.states.push_back(result.final_state);

    result.states.merge(first.states);

    return result;
}

Automata processRegEx(const string& exp)
{
    stack<Automata> s;
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

    return s.top();
}

int main() {
	string exp = "(a|b).(a.b)*.a";

	auto result = processRegEx(infixToPostfix(exp));

//     Automata a('a');
//     Automata b('b');


//    auto r  = concatenation(a,b);

    // concatenation(a,b);
    // for( auto p : a.states)
    // {
    //     cout<<"Transitions for "<<p->id<<endl;
    //     for( auto trans : p->transitions)
    //     {
    //         vector<int> transitions;
    //         for(auto states : trans.second)
    //         {
    //             auto shared_state = shared_ptr(states);
    //             transitions.push_back(shared_state->id);
    //         }
    //         cout<<"On "<<trans.first<<" goes to ";
    //         for(int ids : transitions)
    //         {
    //             cout<<ids<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }

	return 0;
}
