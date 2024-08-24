#include <iostream>

using namespace std;

void display(int** arr,int x,int y);
void display_addr(int** arr,int x,int y);
int* modify(int** arr,int x_index,int y_index,int val);
int main()
{
    int arr[2][5]={{1,2,3,4,5},{5,4,3,2,1}};

    

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