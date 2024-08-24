#include <iostream>

using namespace std;

int add_numbers(int a,int b)
{
    cout<<"Function with two parameters called\n";
    cout<<"Sum of 1st and 2nd : "<<(a+b)<<"\n";
    return a+b;
}
int add_numbers(int a,int b,int c)
{
    cout<<"Function with three parameters called\n";
    cout<<"Sum of 1st ,2nd and 3rd : "<<(a+b+c)<<"\n";
    return a+b+c;
}
int add_numbers(int a,int b,int c,int d)
{
    cout<<"Function with four parameters called\n";
    cout<<"Sum of all numbers : "<<(a+b+c+d)<<endl;
    return a+b+c+d;
}

int main()
{
    int a,b,c,d;
    cout<<"Enter four numbers: ";
    cin>>a>>b>>c>>d;
    cout<<"\n";
    add_numbers(a,b);
    cout<<"\n";
    add_numbers(a,b,c);
    cout<<"\n";
    add_numbers(a,b,c,d);
    cout<<'\n';

}