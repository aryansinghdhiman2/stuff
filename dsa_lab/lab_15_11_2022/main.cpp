#include<iostream>
#include "rec_tree.h"

int main()
{
    Tree t;
    t.insert(9);
    t.insert(2);
    t.insert(23);
    t.insert(4);
    t.insert(8);
    t.insert(20);
    t.insert(24);

    cout<<"In Order: ";
    t.traverse_in_order();
    cout<<'\n';
    t.delete_node(24);
    cout<<'\n';
    t.traverse_in_order();
    cout<<"\ntest";
    // cout<<"Post Order: ";
    // t.traverse_post_order();
    // cout<<'\n';
    // cout<<"Pre Order: ";
    // t.traverse_pre_order();
    // cout<<'\n';

    // cout<<"Height: "<<t.height()<<endl;
    // cout<<"Total Nodes: "<<t.countTotal()<<endl;
    // cout<<"Total Leafs: "<<t.countLeaf()<<endl;
    // cout<<"Nodes with One: "<<t.countOneChild()<<endl;
    // cout<<"Nodes with Two: "<<t.countTwoChild()<<endl;
}