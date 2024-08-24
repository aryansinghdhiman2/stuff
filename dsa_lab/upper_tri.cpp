#include <iostream>

using namespace std;

void enter_values(int**,int);
void display(int**,int);
int main()
{
    cout<<"Enter size of matrix: ";
    int size;
    cin>>size;
    int** arr=new int*[size];
    for(int i=0;i<size;i++)
    {
        arr[i]=new int;
    }

    enter_values(arr,size);
    cout<<'\n';
    display(arr,size);

    for(int i=0;i<size;i++)
    {
        delete arr[i];
    }
    delete [] arr;

}

void enter_values(int** arr,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if((i+j)>(size-1))
            {
                arr[i][j]=0;
            }
            else
            {
                cout<<"Enter element at ("<<i<<","<<j<<"): ";
                cin>>arr[i][j];
            }
        }
    }
}

void display(int** arr,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
}