#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream f("file.txt",ios::in | ios::out);
    string str;

    for(;f;)
    {
        getline(f,str);
        int t=f.tellg();
        cout<<str<<" "<<t<<"\n";
    }
}
