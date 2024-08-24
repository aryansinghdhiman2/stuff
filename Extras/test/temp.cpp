#include <iostream>
using namespace std ;

void display(int*arr, int size)//displays all elements of the array
{
    int i;
    for (i=0 ; i<size ; i++)
    cout<<arr[i]<<" " ;
    cout<< endl;
}

void selectionsort(int*arr, int size)
{ 
    int i, j, imin;
    for (i=0 ; i<size-1 ; i++)//sets starting position at the first element and goes to next element after every iteration
    { 
        imin=i;
        for(j=i+1 ; j<size ; j++)//finds the minimum element in the array
        {
            if (arr[j]<arr[imin])
            {
                imin=j;
            }
        }

        swap(arr[i], arr[imin]);//swaps the minimum element of the array with the element at current starting position
    }
}
int main()
{ 
    int n;
    cout<<"enter no. of elements:";
    cin>> n;
    int arr[n];

    cout<<"enter elements"<<endl;
    for (int i=0 ; i<n ; i++)
    {  
        cin>>arr[i];
    }

    cout<< "array before sort:";
    display (arr, n);
    selectionsort(arr, n);
    cout<<"array after sort:";
    display(arr, n);
    
}