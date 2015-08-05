//
//  main.cpp
//  Maximum Product Subarrray
//
//  Created by Ethan Kho on 7/23/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//#include <algorithm>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_p = nums[0];
        int min_p = nums[0];
        cout<< "working" << nums.size();
        int res = nums[0];
    
        if (nums.size() < 1) return 0;
        for(int i = 1; i < nums.size(); i++)
        {
            int premax = max_p;
            max_p = max(max_p * nums[i], max(min_p * nums[i], nums[i]));
            min_p = min(premax * nums[i], min(min_p * nums[i], nums[i]));
            res = max(res, max_p);
            cout<< res;
            cout<< max_p;
        }
        
        return max_p;
    }
    

};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int arr[5] = {3, 5, 7, 9, 13};
    int var = 0;
    for(int i = 0; i<5; ++i)
    {
        //take the average
        //
    }
    
    
    //int arr[3] = {-4 -3 -2};
    vector<int> nums;
    for(auto i = nums.begin(); i != nums.end(); i++)
    {
        cout<< (*i);
    }
        //cout<< nums.size();
    (new Solution) -> maxProduct(nums);
    return 0;
}
