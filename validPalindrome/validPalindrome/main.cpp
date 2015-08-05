//
//  main.cpp
//  validPalindrome
//
//  Created by Ethan Kho on 6/4/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;;//keep track of the beginnign//need to increment
        long j =  s.length();//keep track of the end; need to decrement
        if(s.length() <= 1)
        {
            return true;
        }

        while(i<j)
        {
            while((!isalnum(s[i])) && (i<j))
            {
                i++;
            }
            while((!isalnum(s[j])) && (i<j))
            {
                j--;
            }
            
            if(tolower(s[i]) != tolower(s[j]))
            {
                return false;
            }
            else
            {
                i++; j--;
            }
            
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //string s ="A man, a plan, a canal: Panama";
    string s = "***";
    bool result = (new Solution)->isPalindrome(s);
    if(result) cout<<"palindrome";
    else cout<<"not palndrome";
    return 0;
}
