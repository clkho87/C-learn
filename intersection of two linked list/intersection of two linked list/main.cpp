//
//  main.cpp
//  intersection of two linked list
//
//  Created by Ethan Kho on 5/29/15.
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
    
    void print(ListNode *head)
    {
        if(head == NULL) return;
        ListNode *cur = head;
        while(cur !=NULL)
        {
            cout<<cur->val;
            cout<<"->";
            cur = cur->next;
            
        }
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //need to find the difference in between
        ListNode *curA = headA;
        ListNode *curB = headB;
        bool Alonger = true;
        while(curA && curB)
        {
            curA = curA -> next;
            curB = curB -> next;
        }
        
        if(curB) Alonger = false;
        else Alonger = true;
        int diff = 0;
        
        if(Alonger)
        {
            while(curA != NULL)
            {
                diff++;
                curA = curA->next;
            }
        }
        else
        {
            while(curB != NULL)
            {
                diff++;
                curB = curB->next;
            }
        }
        cout<<"diff="<<diff;
        curA = headA;
        curB = headB;
        //get the different now
        if(Alonger)
        {
            cout<<"A longer";
            while(diff > 0)
            {
                curA = curA-> next;
                diff--;
            }
        }
        else
        {
            cout<<"blonger";
            while(diff > 0)
            {
                curB = curB->next;
                diff --;
            }
        }
        //same length now
        while(curA && curB)
        {
            if(curA == curB)
            {
                cout<<"found it";
                return curA;
            }
            curA = curA -> next;
            curB = curB -> next;
        }
        cout<<"couldnt find it";
        return NULL;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* four = new ListNode(4);
    ListNode* five = new ListNode(5);
    first->next = second;
    second->next = third;
    third->next = four;
    four->next = five;
    five-> next = NULL;
    (new Solution)->print(first);
    //second linked list
    ListNode* zero1 = new ListNode(4);
    ListNode* first1 = new ListNode(5);
    ListNode* second1 = new ListNode(6);
    zero1->next = first1;
    first1->next = second1;
    second1->next = third;
    cout<<"\n";
    (new Solution)->print(zero1);
    (new Solution)->getIntersectionNode(zero1, first);
    return 0;
}
