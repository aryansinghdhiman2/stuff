#include<vector>
#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return root;

        Node* current = nullptr;
        Node* row_start = root;

        while(row_start!=nullptr)
        {
            current=row_start;
            while(current!=nullptr)
            {
                if(current->left!=nullptr)
                {
                    if(current->right!=nullptr)
                    {
                        current->left->next = current->right;
                    }
                    else
                    {
                        Node* next = current->next;
                        while(next)
                        {
                            if(next->left!=nullptr)
                            {
                                current->left->next = next->left;
                                break;
                            }
                            else if(next->right!=nullptr)
                            {
                                current->left->next = next->right;
                                break; 
                            }
                            next = next->next;
                        }
                    }
                }
                if(current->right!=nullptr && current->next!=nullptr)
                {
                    if(current->next->left!=nullptr)
                    {
                        current->right->next = current->next->left;
                    }
                    else
                    {
                        Node* next = current->next;
                        while(next)
                        {
                            if(next->left!=nullptr)
                            {
                                current->right->next = next->left;
                                break;
                            }
                            else if(next->right!=nullptr)
                            {
                                current->right->next = next->right;
                                break; 
                            }
                            next = next->next;
                        }
                    }
                }

                current = current->next;
            }

            while(row_start!=nullptr)
            {
                if(row_start->left!=nullptr)
                {
                    row_start=row_start->left;
                    break;
                }
                if(row_start->right!=nullptr)
                {
                    row_start=row_start->right;
                    break;
                }
                row_start=row_start->next;
            }

        } 

        return root;
    }
};

int main()
{
    vector<Node> v = {1,2,2,3,3,3,3,4,4,4,4,4,4,0,0,5,5};
    int current = 0;
    while(current<v.size())
    {
        int left = 2*current+1;
        int right = 2*current+2;
        if(left<v.size())
            v.at(current).left = &v.at(left);
        if(right<v.size())
            v.at(current).right = &v.at(right);
        ++current;
    }
    Solution s;
    s.connect(&v.at(0));

    
}