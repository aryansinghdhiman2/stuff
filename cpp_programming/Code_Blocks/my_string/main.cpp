#include <iostream>
#include <My_string.h>
using namespace std;

int main()
{
    My_string s{My_string {"No"}};
    My_string string_1;
    string_1="Hello";
    My_string string_2{"World"};
    My_string string_3{string_1};
    string_3.display();
    string_2.display();
    My_string string_4{"Why?"};
    string_3=string_4;
    string_3.display();
    cout<<boolalpha<<(string_3==string_4)<<noboolalpha<<endl;
    s=s+" "+string_1+" "+string_2;
    s.display();
    s=-s;
    s.display();
    cout<<string_4<<endl;
    cout<<"ENTER ANY SENTENCE"<<endl;
    cin>>string_1;
    cout<<"Why did you enter \""<<string_1<<"\""<<endl;

    return 0;
}
