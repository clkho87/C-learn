//
//  main.cpp
//  isPalindrome
//
//  Created by Ethan Kho on 5/29/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>


class Solution {
public:
    int sum = 0;
    bool isPalindrome(int x) {
        sum = sum*10+x%10;
        x = x/10;
        
        std::cout<<x<<"\n";
        std::cout<<sum<<"\n";
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    bool result = (new Solution()) -> isPalindrome(213);
    std::cout << "Hello, World!\n";
    return 0;
}
