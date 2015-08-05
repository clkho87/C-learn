//
//  main.cpp
//  Add two numbers
//
//  Created by Ethan Kho on 6/16/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry  = 0; int value = 0;
        ListNode *current = l1;
        ListNode *current2 = l2;
        ListNode *prev = new ListNode(0);
        prev->next = l1;

        if(current == NULL)
        {
            return l2;
        }
        else if (current2 == NULL)
        {
            return l1;
        }
        
        while(current != NULL || current2 != NULL)
        {
            if(current == NULL)
            {

                prev->next = current2;
                value  = current2->val + carry;
                current2->val = value % 10;
                carry = value/10;
                current2 = current2->next;
                prev = prev -> next;
                
            }
            else if (current2 == NULL)
            {
                value =  current->val + carry;
                current->val = value%10;
                carry =  value/10;
                current  = current->next;
                prev = prev -> next;
            }
            else
            {
                value = current->val + current2->val + carry;
                current -> val = value%10;
                carry = value/10;
                current = current ->next;
                current2 =  current2 -> next;
                prev = prev -> next;
            }
        }
        
        if(carry)
        {
            ListNode *temp =  new ListNode(carry);
            prev->next = temp;
            prev->next->next = NULL;
        }

        return l1;
        
    }
};

void print (ListNode *node)
{
    while(node != NULL)
    {
        cout<< node->val<< "->";
        node = node -> next;
    }
    cout<<"\n";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //first linked list;
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* four = new ListNode(9);
    ListNode* five = new ListNode(5);
    ListNode* six = new ListNode(6);
    first->next = second;
    second->next = third;
    third->next = four;
    four->next = five;
   //  four->next = NULL;
   // five -> next = NULL;
    five -> next = six;
    six-> next = NULL;
    
    
    //second linked list
    ListNode* first1 = new ListNode(9);
    ListNode* second1 = new ListNode(2);
    ListNode* third1 = new ListNode(3);
    ListNode* four1 = new ListNode(4);
    ListNode* five1 = new ListNode(9);
    ListNode* six1 = new ListNode(6);
    first1->next = second1;
    second1->next = third1;
    third1->next = four1;
    four1->next = five1;
    five1 -> next = six1;
    six1 -> next = NULL;
    
    print(first);
    print(first1);


    ListNode *results = (new Solution) -> addTwoNumbers(first1, first);
    print(results);
    std::cout << "Hello, World!\n";
    return 0;
}
