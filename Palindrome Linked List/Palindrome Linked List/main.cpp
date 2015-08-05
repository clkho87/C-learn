//
//  main.cpp
//  Palindrome Linked List
//
//  Created by Ethan Kho on 8/1/15.
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
    ListNode *reverse_node(ListNode *head)
    {
        
        if(!head || !head->next)
        {
            return head;
        }
        else if(!head->next->next)
        {
            ListNode *first = head;
            ListNode *second = head->next;
            second->next = first;
            first->next = NULL;
            return second;
        }
        
        
        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *temp  = second->next;
        
        
        first->next = NULL;
        while(temp != NULL)
        {
            second->next =  first;
            first =  second;
            second = temp;
            temp = temp->next;
        }
        second->next = first;
        return second;
    };
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        if(!head || !head->next)
        {
            return true;
        }
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        slow->next = NULL;
        ListNode *reverse_ListNode = reverse_node(fast);
        while(reverse_ListNode && reverse_ListNode->val == head->val)
        {
            head = head->next;
            reverse_ListNode =  reverse_ListNode->next;
        }
        
        slow->next = fast;
        
        return reverse_ListNode == NULL;
    }
    
    void print(ListNode *head)
    {
        ListNode *temp = head;
        while(temp !=  NULL)
        {
            cout<< temp->val<< "->";
            temp = temp->next;
        }
        cout<< "NULL"<<"\n";
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *first =  new ListNode(1);
    ListNode *second =  new ListNode(2);
    ListNode *third =  new ListNode(2);
    ListNode *four = new ListNode(1);
    ListNode *five = new ListNode(2);
    ListNode *six = new ListNode(1);
    first->next  = second;
    second->next = third;
    //third->next = NULL;
    third->next = four;
    four->next = NULL;
    /*
    four->next = five;
    five->next = six;
    */
    
    Solution *node = new Solution;
    node->print(first);
    //ListNode *temp = print->reverse_node(first);
    cout<<"\n";
    //print->print(temp);
    bool check = node->isPalindrome(first);
    if (check) cout<< "true";
    return 0;
}