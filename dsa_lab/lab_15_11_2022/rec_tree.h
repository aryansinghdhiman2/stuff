#include<iostream>

using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Tree
{
    Node* head;
    void delete_one_child(Node* ptr);
    void delete_two_child(Node* ptr);
    Node* in_order_succ(Node* ptr);
    void insert(Node* ptr,Node* parent,int data);
    Node* search(Node* ptr,int data);
    void traverse_in_order(Node* ptr);
    void traverse_pre_order(Node* temp);
    void traverse_post_order(Node* temp);
    
    public:
    Tree(){this->head = nullptr;}
    void insert(int data);
    Node* search(int data);
    void traverse_in_order();
    void traverse_pre_order();
    void traverse_post_order();
    void delete_node(int data);
    // ~Tree(){delete this->head}
};

void Tree::insert(int data)
{
    if(this->head==nullptr)
    {
        this->head = new Node;
        head->data = data;
        head->left = head->right = nullptr; 
        return;
    }
    if(data>head->data)
    {
        insert(head->right,head,data);
    }
    else
    {
        insert(head->left,head,data);
    }
}

void Tree::insert(Node* ptr,Node* parent,int data)
{
    
    if(ptr==nullptr)
    {
        ptr = new Node;
        ptr->data = data;
        ptr->left = ptr->right = nullptr;
        if(data>parent->data)
        {
            parent->right = ptr;
            return;
        }
        else
        {
            parent->left = ptr;
            return;
        }
    }

    if(data > ptr->data)
    {
        return insert(ptr->right,ptr,data);
    }
    else
    {
        return insert(ptr->left,ptr,data);
    }
}

Node* Tree::search(int data)
{
    if(this->head==nullptr)
    {
        return nullptr;
    }
    if(data>this->head->data)
    {
        return search(this->head->right,data);
    }
    else if(data < this->head->data)
    {
        return search(this->head->left,data);
    }
    else
    {
        return this->head;
    }
}

Node* Tree::search(Node* ptr,int data)
{
    if(ptr==nullptr)
    {
        return nullptr;
    }
    if(data>ptr->data)
    {
        return search(ptr->right,data);
    }
    else if(data < ptr->data)
    {
        return search(ptr->left,data);
    }
    else
    {
        return ptr;
    }
}

void Tree::traverse_in_order(Node* ptr)
{
    if(ptr == nullptr)
    {
        return;
    }
    this->traverse_in_order(ptr->left);
    cout<<' '<<ptr->data;
    this->traverse_in_order(ptr->right);   
}

void Tree::traverse_in_order()
{
    if(this->head == nullptr)
    {
        return;
    }
    this->traverse_in_order(head->left);
    cout<<' '<<head->data;
    this->traverse_in_order(head->right);
}

void Tree::traverse_pre_order(Node* temp) {
  if (temp != nullptr) {
    cout<< " " << temp->data;
    this->traverse_pre_order(temp->left);
    this->traverse_pre_order(temp->right);
  }
}

void Tree::traverse_pre_order()
{
    if(this->head==nullptr)
    {
        return;
    }
    cout<<' '<<head->data;
    this->traverse_pre_order(head->left);
    this->traverse_pre_order(head->right);
}

void Tree::traverse_post_order(Node* ptr)
{
    if(ptr == nullptr)
    {
        return;
    }
    this->traverse_in_order(ptr->left);
    this->traverse_in_order(ptr->right);   
    cout<<' '<<ptr->data;
}

void Tree::traverse_post_order()
{
    if(this->head == nullptr)
    {
        return;
    }
    this->traverse_in_order(head->left);
    this->traverse_in_order(head->right);
    cout<<' '<<head->data;
}

Node* Tree::in_order_succ(Node* ptr)
{
    Node* temp = ptr->right;
    while(temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
    
}

void Tree::delete_one_child(Node* ptr)
{
    if(ptr==nullptr)
    {
        return;
    }
    Node* temp = ptr;
    if(ptr->left == nullptr)
    {
        ptr = ptr->right;
        delete temp;
        return;
    }
    else
    {
        ptr = ptr->left;
        delete temp;
        return;
    }

}

void Tree::delete_two_child(Node* ptr)
{
    Node* temp = this->in_order_succ(ptr);
    ptr->data = temp->data;
    delete_one_child(temp);
}

void Tree::delete_node(int data)
{
    Node* temp = search(data);
    if(temp==nullptr)
    {
        return;
    }

    if(temp->left == nullptr || temp->right==nullptr)
    {
        delete_one_child(temp);
    }
    else
    {
        delete_two_child(temp);
    }
}