#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int t;
    fstream f("C:\\Users\\Aryan Singh Dhiman\\Desktop\\test\\file.txt",ios::in);
    string str;
    if(!f.is_open())
        cout<<"Not open\n";
    if(f.is_open())
    {
        cout<<"OPEN\n";
    }
    for(;f;)
    {
        getline(f,str);
        t=f.tellg();
        cout<<str<<" "<<"\n";
    }
}