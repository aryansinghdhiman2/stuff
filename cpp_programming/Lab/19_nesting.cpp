#include<iostream>
#include <E:\Programming\cpp_programming\Lab\19_class.h>
using namespace std;

int main()
{
    cout<<"Enter ASCII value\n";
    outer out;
    
    cin>>out.number;

    outer::inner in;
    in.nested_function(out);

    cout<<"Character is : "<<in.c;


}