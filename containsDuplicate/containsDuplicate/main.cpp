//
//  main.cpp
//  containsDuplicate
//
//  Created by Ethan Kho on 5/29/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() < 1)
        {
            return false;
        }
        sort(nums.begin(),nums.end());
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] == nums[i+1])
            {
                return true;
            }
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int myints[] = {16,2,77,29, 16};
    vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
    bool result = (new Solution)->containsDuplicate(fifth);
    if(result)
    {
        std::cout<<"duplicate";
    }
    std::cout << "Hello, World!\n";
    return 0;
}
