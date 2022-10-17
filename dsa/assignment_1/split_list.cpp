#include<iostream>
#include<cmath>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int list_size(Node* head)
{
    if(head==nullptr)
        return -1;
    Node* temp=head;
    for(int i=0;;i++)
    {
        if(temp==nullptr)
            return i;
        temp=temp->next;
    }
}

Node* split(Node* head)
{
    int half=ceil((list_size(head)/2.0));
    Node* temp=head;
    Node* prev=nullptr;
    for(int i=0;i<half;i++)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=nullptr;
    return temp;

}

int main()
{
    Node* head=new Node;
    head->data=0;
    Node* temp=head;
    for(int i=1;i<6;i++)
    {
        temp->next=new Node;
        temp->next->data=i;
        temp=temp->next;
    }
    temp->next=nullptr;

    Node* temp_2=head;
    while(temp_2!=nullptr)
    {
        cout<<temp_2->data<<' ';
        temp_2=temp_2->next;
    }
    cout<<'\n';

    Node* new_list=split(head);
    temp_2=head;
    while(temp_2!=nullptr)
    {
        cout<<temp_2->data<<' ';
        temp_2=temp_2->next;
    }
    cout<<'\n';

    temp_2=new_list;
    while(temp_2!=nullptr)
    {
        cout<<temp_2->data<<' ';
        temp_2=temp_2->next;
    }
    cout<<'\n';
}