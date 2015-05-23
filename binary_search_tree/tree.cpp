//
//  tree.cpp
//  binary_search_tree
//
//  Created by Ethan Kho
//  Copyright (c) 2015 Ethan Kho. All rights reserved.

//  Description: This is class for binary search tree. A tree is a nonlinear, two dimensional data structure with special properties. Tree nodes contain two or more link. The root node is the first node in a tree.  Each link in the root node (A) refers to a child (nodes B and C). This code is for a special binary tree called a binary search tree. A binary search has the characteristic that the values in any left subtree are less than the value in its parent node, and the values in any right subree are greater tahn the values in its parent node. For examples: B below is smaller than A, and C is bigger than A
//             A
//            /  \
//           B    C

#include <iostream>
#include <stdio.h>
#include "tree.h"

//constructor
tree::tree()
{
    root = NULL;
}

//destructor
tree::~tree()
{
    destroy_tree();
}

void tree::destroy_tree(node *leaf)
{
    if(leaf != NULL)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void tree::destroy_tree()
{
    destroy_tree(root);
}

/* function to insert value into the tree */
void tree::insert_node(node *leaf, int value)
{
    if(leaf->data >= value) //value is smaller than parent, goes left
    {
        if(leaf->left != NULL)
        {
            insert_node(leaf->left, value); //recursive since it has value on left
        }
        else
        {
            //if left is NULL
            leaf->left = new node;
            leaf->left->data = value;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
            
        }
    }
    else if(leaf->data < value) // value is bigger than parent, goes right
    {
        if(leaf->right != NULL)
        {
            insert_node(leaf->right, value);// recursive since it has value on right
        }
        else
        {
            leaf->right = new node;
            leaf->right->data = value;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
            
        }
    }
}

void tree::insert(int value)
{
    if( root != NULL)
    {
        insert_node(root, value);
    }
    else
    {
        //create node when it is NULL
        root = new node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
    }
}

/* function to search for target in the tree */
node *tree::search(int value)
{
    return search_node(root, value);
}

node *tree::search_node(node *leaf, int value)
{
    if( leaf != NULL)
    {
        if(leaf->data == value)
        {
            return leaf;
        }
        else if(leaf->data >= value)
        {
            //need to do recursion to find
            return search_node(leaf->left, value);
        }
        else if (leaf-> data < value)
        {
            return search_node(leaf->right, value);
        }
    }
    else
    {
        return NULL;
    }
    return NULL;
}

/* function to get the preorder values from tree */
void tree::preorder()
{
    preorderhelper(root);
    
}
void tree::preorderhelper(node *ptr)
{
    if(ptr != 0)
    {
        std::cout<<ptr->data<< " ";
        preorderhelper(ptr->left);
        preorderhelper(ptr->right);
        
    }
}

/* function to get the inorder values from tree */
void tree::inorder()
{
    inorderhelper(root);
}

void tree::inorderhelper(node *ptr)
{
    if(ptr != 0)
    {
        
        inorderhelper(ptr->left);
        std::cout<<ptr->data<<' ';
        inorderhelper(ptr->right);
        
    }
}

/* function to get the postoder values from tree */
void tree::postorder()
{
    postorderhelper(root);
}

void tree::postorderhelper(node *ptr)
{
    if(ptr != 0)
    {
        
        postorderhelper(ptr->left);
        postorderhelper(ptr->right);
        std::cout<<ptr->data<<' ';
        
    }
}

/* function to get all the sum of the BST */
int tree::sum_helper(node *leaf)
{
    if(leaf == NULL)
    {
        return 0;
    }
    else
    {
        return leaf->data + sum_helper(leaf->left) +  sum_helper(leaf->right);
    }
}

void tree::sum()
{
    if(root != NULL)
    {
        int total = sum_helper(root);
        std::cout << " \n Total is = " <<total << "\n";
    }
    else
    {
        std::cout<<" \n Root is empty \n";
    }
}

/* function to get the minimum value in the binary search tree */
void tree::min()
{
    if(root == NULL)
    {
        std::cout<<"\n The root is NULL \n ";
    }
    else
    {
        min_help(root);
    }
}
void tree::min_help(node* leaf)
{
    if(leaf->left != NULL)
    {
        min_help(leaf->left);
    }
    else
    {
        std::cout<<" \n Smallest element in BST is "<<leaf->data << "\n";
    }
}

/* function to get the minimum value in the binary search tree */
int tree::maxDepth()
{
    if(root == NULL)
    {
        std::cout<<"\n The root is NULL \n ";
        return 0;
    }
    else
    {
        return maxDepthHelper(root);
    }
}

/* function to get the maximum depth helper */
int tree::maxDepthHelper(node* node)
{
    if(node == NULL)
    {
        return 0;
    }
    else
    {
        // compute the depth of each subtree
        int leftDepth = maxDepthHelper(node->left);
        int rightDepth = maxDepthHelper(node->right);
        // use the larger one
        if (leftDepth > rightDepth)
        {
            return(leftDepth+1);
        }
        else
        {
            return(rightDepth+1);
        }
    }
}

