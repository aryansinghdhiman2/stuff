#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string str)
{
    string temp;
    for(int i=(int(str.size())-1);i>=0;i--)
    {
        temp.push_back(str.at(i));
    }
    if(temp==str)
        return 1;
    else 
        return 0;
}

int main()
{
    string str;
    cout<<"Enter String:";
    getline(cin,str);
    cout<<boolalpha;
    cout<<"String is palindrome :"<<is_palindrome(str)<<endl;
}

