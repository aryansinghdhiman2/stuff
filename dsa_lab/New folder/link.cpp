#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head=nullptr;

int main()
{
    int c;
    cout<<"1.Create\n 2.Insert at beginning \n3.Insert at end \n4.Insert by position \n5.Delete at beginning \n6.Delete at end\n7.Delete by position \n8.Search";
    cout<<"enter desired operation:";
    cin>>c;

    switch (c)
    {
    case 1:
    {
        int val;
        cout<<"Enter a value";
        cin>>val;
        head = new Node;
        head->data=val;
        head->next=nullptr;
        cout<<"List created";
        break;
    }
    case 2:
    {
        int val;
        cout<<"Enter a value";
        cin>>val;
        Node* temp = new Node;
        temp->data=val;
        temp->next=head;
        head = temp;
        break;
    }
    case 3:
    {
        int val;
        cout<<"Enter a value";
        cin>>val;
        Node* temp = new Node;
        temp->data=val;
        Node* temp_2 = head;
        while(temp_2->next!=nullptr)
        {
            temp_2=temp_2->next;
        }
        temp_2->next=temp;
        break;
    }
    case 4:
    {
        int pos;
        cout<<"Enter position";
        cin>>pos;
        int val;
        cout<<"Enter a value";
        cin>>val;
        Node* temp = new Node;
        temp->data=val;
        Node* temp_2=head;
        Node* prev=nullptr;
        for(int i=0;temp_2!=nullptr;i++)
        {
            if(i==pos)
            {
                
            }
        }
    }
    default:
        break;
    }

}