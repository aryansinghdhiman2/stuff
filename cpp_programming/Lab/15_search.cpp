#include <iostream>

using namespace std;

int linear_search(const int source[],int length,int element);
int binarySearch(int source[],int length,int element);
void bubble_sort(int arr[],int size_of_array);

int main()
{
    cout<<"Enter length of array: ";
    int len;
    cin>>len;

    cout<<"Enter elements of the array: ";
    int *arr=new int[len];
    for(int i=0;i<len;i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter element to be searched: ";
    int element_find;
    cin>>element_find;

    bubble_sort(arr,len);//array needs to be sorted in case it has to be used with binary search

    cout<<"\nBy Linear Search\n\n";
    int temp=linear_search(arr,len,element_find);
    if(temp!=(-1))
        cout<<"Element "<<element_find<<" is at the position :"<<temp+1<<endl;
    else
        cout<<"Element not found\n";


    cout<<"\nBy Binary Search\n\n";
    int temp_2=binarySearch(arr,len,element_find);
    if(temp_2!=(-1))
        cout<<"Element "<<element_find<<" is at the position :"<<temp_2+1<<endl;
    else
        cout<<"Element not found\n";

    delete [] arr;
    return 0;
}


int linear_search(const int source[],int length,int element)
{
    int i=0;
    for(i=0;i<length;i++)//goes through the array one by one and compares each element with with the element to be found
    {
        if(source[i]==element)
        {
            return i;
        }
    }
    if(i==(length))
        return -1;
    
    return 0;
}

int binarySearch(int source[],int length,int element)
{
    int end_of_array,start_of_array,middle_of_array;
    end_of_array=length-1;
    start_of_array=0;

    while(start_of_array<=end_of_array)
    {
        middle_of_array=(end_of_array+start_of_array)/2;//finds the middle element of the array
        if(source[middle_of_array]==element)//if middle element is equal to element to be found returns middle element
            return middle_of_array;
        else if(source[middle_of_array]>element)
        //if middle element is greater than element to be found then the left half of the array is taken in next iteration
            end_of_array=middle_of_array-1;
        else//if middle element is smaller than right half of the array is taken in next iteration
            start_of_array=middle_of_array+1;
    }
    return -1;
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