#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

int getNth(Node* head,int index)
{
    if(head==nullptr){
        cout<<"List is Empty\n";
        return -1;
    }
    else
    {
        Node* temp=head;
        for(int i=0;;i++)
        {
            if(temp==nullptr)
            {
                cout<<"Index not found\n";
                return -1;
            }
            if(i==index)
            {
                return temp->data;
            }
            temp=temp->next;
        }
    }

}


int main()
{
    Node one;
    one.data=1;
    Node two;
    two.data=2;
    one.next=&two;
    Node three;
    three.data=3;
    two.next=&three;
    three.next=nullptr;
    cout<<getNth(&one,4);
}