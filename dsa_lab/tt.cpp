#include <stdlib.h>
#include <iostream>
using namespace std;

struct node {
  int data;
  struct node *left;

  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}

//traverse preorder
void traversePreOrder(struct node *temp) {
  if (temp != NULL) {
    cout<< " " << temp->data;
    traversePreOrder(temp->left);
    traversePreOrder(temp->right);
  }
}

// Traverse Inorder
void traverseInOrder(struct node *temp) {
  if (temp != NULL) {
    traverseInOrder(temp->left);
    cout<< " " << temp->data;
    traverseInOrder(temp->right);
  }
}

// Traverse Postorder
void traversePostOrder(struct node *temp) {
  if (temp != NULL) {
    traversePostOrder(temp->left);
    traversePostOrder(temp->right);
    cout << " " << temp->data;
  }
}

int main() {
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  int c;
  cout<<"Enter which order traversal you want: 1)Pre order Traversal\n 2)In order traversal\n 3)Post order traversal\n 4) Exit "<<endl;
  cin>>c;
  
  
    
  switch (c)
  {
  case 1:
  cout << "preorder traversal: ";
  traversePreOrder(root);
  break;
  case 2:
  cout<< "\nInorder traversal: ";
  traverseInOrder(root);
  break;
  case 3:
  cout << "\nPostorder traversal: ";
  traversePostOrder(root);
    break;
  }
  
}