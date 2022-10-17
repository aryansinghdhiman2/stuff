#include <iostream>
using namespace std;

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (i <= pivot)
        {
            i++;
        }
        while (j > pivot)
        {
            j--;
        }
        if (i < j)
        {

            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int pivotindex;
    if (low < high)
    {
        pivotindex = partition(A, low, high);
        quickSort(A, low, pivotindex-1);
        quickSort(A, pivotindex + 1, high);
    }
}
int main()
{
    int A[] = {3, 65, 1, 4, 87, 9, 23};
    int n = 7;
    display(A, n);
    quickSort(A, 0, n-1);
    display(A, n);
}