#include <iostream>

using namespace std;

int main()
{
    int n, i, largest, smallest;
    cout << "enter size of array" << endl;
    cin >> n;
    int* arr=new int[n];
    cout << "enter elements of array";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    largest = arr[0];
    for (i = 0; i < n; i++)
    {
        if (largest < arr[i])
            largest = arr[i];
    }
    smallest = arr[0];
    for (i = 0; i < n; i++)
    {
        if (smallest > arr[i])
            smallest = arr[i];
    }
    cout << "largest number=" << largest << endl;
    cout << "smallest number=" << smallest << endl;

    delete [] arr;
    return 0;
}