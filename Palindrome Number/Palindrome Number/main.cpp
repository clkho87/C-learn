//
//  main.cpp
//  Palindrome Number
//
//  Created by Ethan Kho on 5/29/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
class Solution {
public:
    bool isPalindrome(int x) {
        long reverse = 0;
        int copy = x;
        if(x < 0)
            return false;
        while(copy > 0)
        {
            reverse = reverse * 10;
            reverse = reverse + copy%10;
            copy = copy/10;
        }
        std::cout<<reverse;
        if((reverse - x) == 0)
            return true;
        else
            return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    bool result = (new Solution)-> isPalindrome(123);
    if(result)std::cout<<"is palindrome \n";
    std::cout << "Hello, World!\n";
    return 0;
}
