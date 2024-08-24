#include <iostream>

using namespace std;

void swap(int a,int b)
{
    cout<<"Numbers before swapping in swap function: "<<a<<" "<<b<<endl; 
    int temp=a;
    a=b;
    b=temp;
    cout<<"Numbers after swapping in swap function: "<<a<<" "<<b<<endl;
}
void swap_ptr(int* a,int* b)
{
    int* temp=new int{*a}; 
    *a=*b;
    *b=*temp;
    delete temp;
}

int main()
{
    int a,b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    swap(a,b);

    cout<<"Numbers before swapping using pointer: "<<a<<" "<<b<<endl;

    swap_ptr(&a,&b);

    cout<<"Numbers after swapping using pointer: "<<a<<" "<<b<<endl;

}