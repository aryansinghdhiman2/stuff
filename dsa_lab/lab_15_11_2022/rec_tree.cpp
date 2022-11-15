struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Tree
{
    Node* head;
    Tree(){this->head = nullptr;}
    public:
    void insert(Node* ptr,Node* parent,int data);
    Node* search(Node* ptr,int data);

};

void Tree::insert(Node* ptr,Node* parent,int data)
{
    if(this->head==nullptr)
    {
        this->head = new Node;
        head->data = data;
        head->left = head->right = nullptr; 
        return;
    }

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