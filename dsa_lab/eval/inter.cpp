#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

Node* intersect(Node* head_1,Node* head_2)
{
    for(Node* temp_1 = head_1;temp_1 != nullptr;temp_1 = temp_1->next)
    {
        for(Node* temp_2 = head_2;temp_2 != nullptr;temp_2 = temp_2->next)
        {
            if(temp_1 == temp_2)
            {
                return temp_1;
            }
        }
    }
    
    return nullptr;
}

int main()
{
    Node* a = new Node{1,nullptr};
    Node* b = new Node{2,nullptr};
    a->next = b;
    Node* c = new Node{3,nullptr};
    b->next = c;
    Node* d = new Node{4,nullptr};

    Node* z = new Node{20,nullptr};
    Node* y = new Node{30,nullptr};
    z->next = y;
    Node* x = new Node{23,nullptr};
    y->next = x;
    x->next = c;

    Node* result=intersect(a,z);

    if(result == nullptr)
    {
        cout<<"No intersect\n";
        return 0;
    }
    else
    {
        cout<<"Intersecting Node is: "<<result->data;
        return 0;
    }
    return 0;
}