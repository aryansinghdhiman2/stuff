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
    t.traverse_in_order();
    cout<<'\n';
    t.traverse_post_order();
    cout<<'\n';
    t.traverse_pre_order();
}