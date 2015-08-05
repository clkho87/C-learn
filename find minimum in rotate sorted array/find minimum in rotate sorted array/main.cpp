//
//  main.cpp
//  find minimum in rotate sorted array
//
//  Created by Ethan Kho on 6/14/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        //4 5 6 1 2 3
        //find min using binary search
        //compare with the middle index, and then compare with the start and end index
        //break when you find that the intersection- when it is
        
            int left = 0,  right = nums.size() - 1;
            while(left < right) {
                if(nums[left] < nums[right])
                    return nums[left];
                
                int mid = (left + right)/2;
                if(nums[mid] > nums[right])
                    left = mid + 1;
                else
                    right = mid;
            }
            
        return nums[left];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    //vector<int> nums = {5, 6, 7, 8, 0, 1, 2, 3, 4};
   // vector<int> nums = {5,6,1,2,3,4};
    vector<int> nums = {9,8,7,6,5,4,2,1,0};
    int result = (new Solution) -> findMin(nums);
    cout<< result;
    std::cout << "Hello, World!\n";
    return 0;
}
