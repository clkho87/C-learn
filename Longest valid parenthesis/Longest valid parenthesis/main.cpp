//
//  main.cpp
//  Longest valid parenthesis
//
//  Created by Ethan Kho on 6/17/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int size  = (int) s.length();
        stk.push(-1);
        int len = 0;
        for(int i = 0; i < size; i++)
        {
            int top = stk.top();
            if(top != -1 && s[top] == '(' && s[i] == ')')
            {
                stk.pop();
                len = max(len, i -  stk.top());
            }
            else
            {
                stk.push(i);
            }
        }
        return len;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string s  = "))((()))()";
    int result = (new Solution) -> longestValidParentheses(s);
    //cout<< result;
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(10);
    cout<< stk.top();
    stk.pop();
    stk.pop();
    stk.pop();
    //stk.pop();
    
    //std::cout << "Hello, World!\n";
    return 0;
}
