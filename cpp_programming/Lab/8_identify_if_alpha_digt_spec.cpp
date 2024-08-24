#include <iostream>
#include <cctype>
using namespace std;
// is character/digit/symbol
int main()
{
    cout<<"Enter character/digit/symbol: ";
    char ch;
    cin>>ch;
    
    if(isalpha(ch))
        cout<<"You have entered a Character";
    else if(isdigit(ch))
        cout<<"You have entered a Number";
    else
        cout<<"You have entered a Special Symbol";

    return 0;
}