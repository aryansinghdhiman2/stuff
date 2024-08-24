#include <iostream>

using namespace std;

void bubble_sort(int arr[],int size_of_array);
void selection_sort(int arr[],int size_of_array);

int main()
{
    cout << "Enter number of elements in the array to be sorted: ";
    int num;
    cin>>num;
    int *arr_1=new int[num];
    int *arr_2=new int[num];
    cout<<"Enter elements of the array"<<endl;
    for(int i=0;i<num;i++)
    {
        cin>>arr_1[i];
        arr_2[i]=arr_1[i];
    }
    cout<<"\nArray after bubble sort"<<endl;

    bubble_sort(arr_1,num);

    for(int i=0;i<num;i++)
    {
        cout<<arr_1[i]<<" ";
    }

    selection_sort(arr_2,num);
    cout<<"\n\nArray after selection sort"<<endl;
    for(int i=0;i<num;i++)
    {
        cout<<arr_2[i]<<" ";
    }

    delete [] arr_1;
    delete [] arr_2;
    return 0;
}

void bubble_sort(int arr[],int size_of_array)
{
    for(int l=0;l<size_of_array-1;l++)//bubble sort
    {
        if(arr[l]>arr[l+1])
        {
        int temp=arr[l];
        arr[l]=arr[l+1];
        arr[l+1]=temp;
        l=-1;
        }
    }
}

void selection_sort(int arr[],int size_of_array)
{
    int checker=1;
    for(int n=0;;n++)
    {
        checker=0;
        int minimum=arr[n],position=n;
        for(int t=n+1;t<size_of_array;t++)//selecting element of minimum size and finding its position
        {
            if(arr[t]<minimum)
            {
                minimum=arr[t];
                position=t;
                checker++;
            }
        }
        if(checker==0)
            break;
        arr[position]=arr[n];//swapping minimum with starting position
        arr[n]=minimum;

    }

}
