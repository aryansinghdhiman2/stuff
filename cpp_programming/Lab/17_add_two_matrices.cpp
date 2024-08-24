#include <iostream>

using namespace std;

int** add_two_array(int **arr,int **arr_2,int length,int width);

int main()
{
    cout << "Enter the dimensions of the matrices" << endl;
    int length,width;
    cin>>length>>width;

    int **first=new int*[length];//initializing array
    int **second=new int*[length];
    for(int k=0;k<length;k++)
    {
        first[k]=new int[width];
        second[k]=new int[width];
    }

    cout<<"Enter elements of the first array\n";

    for(int i=0;i<length;i++)
        for(int j=0;j<width;j++)
            cin>>first[i][j];

    cout<<"\nEnter elements of the second array\n";

    for(int i=0;i<length;i++)
        for(int j=0;j<width;j++)
            cin>>second[i][j];

    add_two_array(first,second,length,width);

    for(int k=0;k<length;k++)//deallocating memory
    {
        delete [] first[k];
        delete [] second[k];
    }
    delete [] first;
    delete [] second;

    return 0;
}

int** add_two_array(int **arr,int **arr_2,int length,int width)
{
    cout<<"Array after addition is :\n\n";
    int **temp=new int*[length];//allocating memory
    for(int k=0;k<length;k++)
    {
        temp[k]=new int[width];
    }

    for(int i=0;i<length;i++)//adding each element
    {
        for(int j=0;j<width;j++)
        {
            temp[i][j]=arr[i][j]+arr_2[i][j];
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
    return temp;
}
