//
//  main.cpp
//  Valid Parentheses
//
//  Created by Ethan Kho on 7/10/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
        if(s.length() < 2)
        {
            return false;
        }
        stack<char> stk;
        for(int i  = 0 ; i < s.length(); i++)
        {
            if(stk.empty())
            {
                stk.push(s[i]);
            }
            else if((stk.top() ==  s[i] - 1) || (stk.top() == s[i] - 2))
            {
                stk.pop();
            }
            else
            {
                stk.push(s[i]);
            }
        }
        if(stk.empty())return true;
        else return true;
    }
};

int main(int argc, const char * argv[]) {
    string s = "{{}}";
    bool result = (new Solution)->isValid(s);
    
    if(result) cout<<"true \n";
        else cout<<"false \n";
    
    return 0;
    
}
