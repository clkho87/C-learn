//
//  main.cpp
//  Merge two sorted list
//
//  Created by Ethan Kho on 7/10/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
        {
            return l2;
        }
        else if (l2 ==  NULL)
        {
            return l1;
        }
        
        ListNode *current1 = l1;
        ListNode *current2 = l2;
        ListNode *root = NULL;
        ListNode *current = root;
        while((current1 != NULL) ||  (current2 != NULL))
        {
           // cout<<current1->val;
            if(current1 == NULL)
            {
                current -> next = new ListNode(current2 -> val);
                current = current ->next;
                current2 =  current2 -> next;
            }
            else if (current2 == NULL)
            {
                
                current -> next = new ListNode(current1 -> val);
                current = current ->next;
                current1 =  current1 -> next;
                
            }

            else if(current1-> val >= current2->val)
            {
                
                if(root == NULL)
                {
                    root = new ListNode(current2->val);
                    current = root;
                    current2 = current2->next;

                }
                else
                {
                    current -> next = new ListNode(current2 -> val);
                    current = current ->next;
                    current2 =  current2 -> next;
                }
            }
            else if( current1->val < current2->val)
            {
                if(root == NULL)
                {
                    root = new ListNode(current1->val);
                    current = root;
                    current1 =  current1->next;
                }
                else
                {
                    current -> next = new ListNode(current1 -> val);
                    current = current ->next;
                    current1 =  current1 -> next;
                }
             }
        }
        return root;
    }
    
    
    void print(ListNode *node)
    {
        ListNode *current = node;
        if(current == NULL)
        {
            return;
        }
        else
        {
            while(current != NULL)
            {
                cout<< current->val<< " ->";
                current = current->next;
            }
        }
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode *l1 =  new ListNode(1);
    ListNode *a1 =  new ListNode(2);
    ListNode *a2 =  new ListNode(3);
    ListNode *a3 =  new ListNode(4);
    l1->next = a1;
    a1->next = a2;
    a2->next = a3;
    
    ListNode *l2 =  new ListNode(2);
    ListNode *b1 =  new ListNode(4);
    ListNode *b2 =  new ListNode(6);
    ListNode *b3 =  new ListNode(8);
    ListNode *b4 =  new ListNode(10);
    l2->next = b1;
    b1->next = b2;
    b2->next = b3;
    b3->next = b4;

    ListNode *result = (new Solution) -> mergeTwoLists(l1, l2);
    (new Solution) -> print(result);
    
    return 0;
}
