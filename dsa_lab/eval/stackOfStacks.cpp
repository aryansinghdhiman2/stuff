#include<iostream>
using namespace std;
// struct Node
// {
//     int data;
//     Node* next;
// };


class stack
{
    int top=-1;
    int stack_array[5];
    public:
    int push(const int data)
    {
        if(top == 4)
        {
            cout<<"Stack Overflow";
            throw -1;
        }
        else
        {
            top++;
            stack_array[top] = data;
            return stack_array[top];
        }
        return 0;
    }
    int pop()
    {
        if(top == -1)
        {
            cout<<"Stack underflow";
            throw -1;
        }
        else
        {
            int temp = stack_array[top];
            top--;
            return temp;
        }
        return 0;
    }
    int depth() {return top;}
};

struct stackNode
{
    stack s;
    stackNode* next=nullptr;
};

class stackOfStacks
{
    // int stack[5];
    stackNode* head=nullptr;
    // stackNode* tail=nullptr;
    public:
    int push(const int data)
    {
        if(head == nullptr)
        {
            head = new stackNode;
            return head->s.push(data);
            
        }
        stackNode* prev=nullptr;
        for(stackNode* temp=head;temp!= nullptr;temp = temp->next)
        {
            if(temp->s.depth() == 4)
            {
                prev = temp;
                continue;
            }
            else
            {
                return temp->s.push(data);
            }
            prev = temp;
        }
        prev->next = new stackNode;
        return prev->next->s.push(data);
    }
    int pop()
    {
        if(head==nullptr)
        {
            cout<<"Underflow";
            throw -1;
        }
        stackNode* prev=nullptr;
        stackNode* temp=head;
        for(;temp->next!=nullptr;temp=temp->next){
            prev = temp;
        }
        if(temp->s.depth()==-1)
        {
            delete temp;
            temp = nullptr;
            if(prev == nullptr)
            {
                cout<<"Overflow";
                throw -1;
            }
            prev->next = nullptr;
            return prev->s.pop();
        }
        else
        {
            return temp->s.pop();
        }
        
    }
};

int main()
{
    stackOfStacks s;
    for(int i=0; i<25 ;i++)
    {
        s.push(i);
    }
    for(int i=0; i<25 ;i++)
    {
        cout<<s.pop()<<' ';
    }
    cout<<' ';
}