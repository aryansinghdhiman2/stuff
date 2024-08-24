#include <iostream>

using namespace std;

void insert_element(int*,int,int,int);

int main()
{
    cout <<"Enter length of list: ";
    int length=0;
    cin>>length;

    int* lis=new int[length];
    cout<<"Enter elements of the list: ";
    for(int i=0;i<length;i++)
    {
        cin>>lis[i];
    }

    cout<<"Enter number to be inserted: ";
    int number=0;
    cin>>number;

    cout<<"Enter position to be inserted at: ";
    int pos=0;
    for(;;)
    {
        cin>>pos;
        if(pos<=length)
            break;
        else
            cout<<"Invalid position"<<endl;
    }
    insert_element(lis,length,number,pos);

    cout<<"List after insertion: ";
    for(int i=0;i<length+1;i++)
    {
        cout<<lis[i]<<" ";
    }

    delete [] lis;

    return 0;
}

void insert_element(int* source,int src_len,int element,int position)//{1,2,3,4},4,0,3
{
    int* temp=new int[src_len+1];

    for(int i=0;i<position-1;i++)//add elements in temp till the position to be inserted
    {
        temp[i]=source[i];
    }                       //after completion of loop temp={1,2}
//  add the element to be inserted
    temp[position-1]=element;//temp={1,2,0}

    for(int j=position-1,k=position;j<src_len;j++,k++)//add the rest of the elements
    {
        temp[k]=source[j];
    }                       //after completion of loop={1,2,0,3,4}

    delete [] source;//deleting source's memeory
    source=new int[src_len+1];
    for(int i=0;i<src_len+1;i++)//copying elements in temp to source
        source[i]=temp[i];
    delete [] temp;//deleting temp's memory
}
