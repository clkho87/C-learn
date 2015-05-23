//
//  tree.h
//  binary_search_tree
//
//  Created by Ethan Kho
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#ifndef binary_search_tree_tree_h
#define binary_search_tree_tree_h


#endif

#include "node.h"

class tree
{
private:
    node *root;
    void preorderhelper(node *leaf);
    void inorderhelper(node *leaf);
    void postorderhelper(node *leaf);
    void insert_node(node *leaf, int value);
    node* search_node(node *leaf, int value);
    void min_help(node *leaf);
    int sum_helper(node *leaf);
    void destroy_tree(node *leaf);
    void destroy_tree();
    int maxDepthHelper(node *);

public:
    tree();
    ~tree();
    void insert(int value);
    node* search(int);
    void preorder();
    void inorder();
    void postorder();
    void min();
    void sum();
    int maxDepth();
};
