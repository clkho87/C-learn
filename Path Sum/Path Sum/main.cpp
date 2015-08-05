
//  main.cpp
//  Path Sum
//
//  Created by Ethan Kho on 6/18/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

class Solution {
public:
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL && root->val == sum )return true;
        else
            return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
