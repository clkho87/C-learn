//
//  main.cpp
//  binary_search_tree
//
//  Created by Ethan Kho 
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include "tree.h"
#include "node.h"


int main(int argc, const char * argv[])
{
    int intNumber;
    int intValue;
    
    std::cout << " How many integers do you want to enter? \n";
    std::cin >> intNumber;
    
    //while loop to check to see whether it is actually integer
    while(std::cin.fail())
    {
        std::cout << " Error, input is not an integer, Please retry \n";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> intNumber;
    }

        
    std::cout << " Enter "<< intNumber <<" integer values: \n";
    tree tree_link;
    for(int i = 0; i < intNumber; i ++)
    {
        std::cin >> intValue;
        //while loop to check to see whether it is integer
        while(std::cin.fail())
        {
            std::cout << " Error, input is not an integer, Please retry \n";
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> intValue;
        }
        tree_link.insert(intValue);
        
    }
 
    std::cout<<"\n Preorder Traversal \n";
    tree_link.preorder();
    std::cout<<"\n Inorder Traversal \n";
    tree_link.inorder();
    std::cout<<"\n Postorder Traversal \n";
    tree_link.postorder();
    
    /* searching for the minimum value in the BST */
    tree_link.min();
    
    /*searching for target value in the BST */
    int findValue = 4;
    bool check = tree_link.search(findValue);
    if(check)
    {
        std::cout<<"The value " << findValue << " found";
    }
    else
    {
        std::cout<<"The value " << findValue << " not found";
    }
    
    /* searching for the sum of the BST of all leafs */
    tree_link.sum();
    
    /* Searching for the max depth of the BST */
    int max = tree_link.maxDepth();
    std::cout<< "The Maximum depth of the tree is " << max << "\n";
    
    tree_link.~tree();
    return 0;
}
