//
//  main.cpp
//  productExceptSelf
//
//  Created by Ethan Kho on 7/21/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> productArray;
        int products = 1;
        

        
        for(int i = 0; i < nums.size(); i++)
        {
            productArray.push_back(1);
        }
        
        if (nums.size() < 2)
        {
            return productArray;
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            productArray[i] = products;
            products = products * nums[i];
        }
        
        products  = 1;

        for(long i = nums.size() - 1; i >= 0; --i)
        {
            cout<<productArray[i];
            productArray[i] = productArray[i] * products;
            products = products * nums[i];
        }
        
        return productArray;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums = {0, 0};
    vector<int> result;
    result = (new Solution) -> productExceptSelf(nums);
    
    for(int i = 0; i < nums.size(); i++)
    {
        cout<<result[i]<<",";
    }
    std::cout << "Hello, World!\n";
    return 0;
}
