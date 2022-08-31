#include <iostream>

using namespace std;

void swap_ptr(int** a,int** b)
{
    int** temp=new int*;
    *temp=new int{**a}; 
    **a=**b;
    **b=**temp;
    delete *temp;
    delete temp;
}

int main()
{
    int a,b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    int* a_ptr=&a;
    int* b_ptr=&b;
    cout<<"Numbers before swapping using pointer: "<<a<<" "<<b<<endl;
    swap_ptr(&a_ptr,&b_ptr);
    cout<<"Numbers after swapping using pointer: "<<a<<" "<<b<<endl;

}