//
//  main.cpp
//  Contains_Duplicate2
//
//  Created by Ethan Kho on 6/4/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //int k = j - i; //need to find the max indices
        // iterate to find the same nums[i] == nums[j] and then break when it reaches k
        //2 for loops
        // first is the value, second is the index
        unordered_map<int, int> tracker;

        for(int i = 0; i < nums.size(); i++)
        {
            if(tracker.find(nums[i]) != tracker.end() && i - tracker[nums[i]] <= k) return true;
            else tracker[nums[i]] = i;
            
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
 //   vector <int> nums{1,2,3,4,-13,7,9,-13};
 vector <int> nums{99, 99};
    //  int array[] = {2,5,1,7,9,23,4,55,24};
   // int size  = 9;
    //insertion_sort(array, size);
    bool results = (new Solution)->containsNearbyDuplicate(nums, 2);
    cout<< results;

    
    return 0;
}
