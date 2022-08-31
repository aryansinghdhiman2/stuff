#include <iostream>

using namespace std;

void display(int arr[],int len);
void display_addr(int arr[],int len);
int* modify(int arr[],int index_to_mod,int val);
int main()
{
    int arr[5]={1,2,3,4,5};
    display(arr,5);
    display_addr(arr,5);
    arr[0]=5;
    arr[1]=4;
    arr[2]=3;
    arr[3]=2;
    arr[4]=1;
    cout<<'\n';
    display(arr,5);
    display_addr(arr,5);

    int* ptr=modify(arr,3,0);
    cout<<"\nAddress of modified element: "<<ptr<<" ,Modified Value: "<<*ptr<<endl;
    display(arr,5);

    

}

void display(int arr[],int len)
{
    cout<<"Displaying array\n";
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] <<" ";
    }
    cout<<'\n';
}

void display_addr(int arr[],int len)
{
    cout<<"Displaying array addresses\n";
    for (int i = 0; i < len; i++)
    {
        cout << arr+i <<" ";
    }
    cout<<'\n';
}

int* modify(int arr[],int index_to_mod,int val)
{
    int* p=arr;
    p[index_to_mod]=val;
    return (p+index_to_mod);
}