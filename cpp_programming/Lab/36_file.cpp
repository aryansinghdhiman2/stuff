#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input("36_file.txt");
    if(!input.is_open())
    {
        cout<<"File could not be opened\n";
    }
    else
    {
        string str;
        for(;input;)
        {
            if(getline(input,str))
                cout<<str<<endl;
        }
    }
}