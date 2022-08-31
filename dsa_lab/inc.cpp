#include <iostream>

using namespace std;

void increment_by_val(int a,int b)
{
    a++;
    b++;
}

void increment_by_ref(int* a,int* b)
{
    (*a)++;
    (*b)++;
}

int main()
{
    int a,b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;

    cout<<"Numbers before incrementing are: "<<a<<" "<<b<<endl;
    increment_by_val(a,b);
    cout<<"Numbers after incrementing by value are: "<<a<<" "<<b<<endl;
    increment_by_ref(&a,&b);
    cout<<"Numbers after incrementing are by reference are: "<<a<<" "<<b<<endl;


}