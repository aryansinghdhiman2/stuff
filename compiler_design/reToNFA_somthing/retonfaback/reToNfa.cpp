#include <stack>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>
#include <stack>
#include "./parse.h"
#include "./automata.hpp"

int main() {

    string input;
    std::vector<char> alphabets;
    
    std::cout<<"Enter Accepted Alphabets: ";
    std::getline(std::cin,input);
    std::stringstream input_stream(input);
    while(std::getline(input_stream,input,' '))
    {
        alphabets.push_back(input.at(0));
    }
    alphabets.push_back(epsilon);

    std::cout<<"Enter Regular Expression: ";
    input.clear();
    std::cin>>input;

    Automata nfa = processRegEx(infixToPostfix(input));

    printAutomata(nfa,alphabets);
    
    alphabets.pop_back();
    auto dfa = convertToDFA(nfa.initial_state,alphabets);
    printAutomata(dfa,alphabets);
	return 0;
}
