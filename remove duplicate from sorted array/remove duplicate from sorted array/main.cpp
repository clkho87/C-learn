//
//  main.cpp
//  remove duplicate from sorted array
//
//  Created by Ethan Kho on 6/8/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
        {
            return (int) nums.size();
        }

        int nindex = 0;
        bool repeat = false;
        for(int i = 0; i<nums.size(); i++)
        {
            // same same
            if((repeat == true) && (nums[i] == nums[i+1]))
            {
                repeat = true;
                //dont have to save coz already save last time
            }
            else if((!repeat) && (nums[i] == nums[i +1]))
            {
                //xsame same
                repeat = true;
                nums[nindex] = nums[i];
                ++nindex;
            }
            else if((repeat) && (nums[i] != nums[i+1]))
            {
                // same xsame
                repeat = false;
            }
            else if((!repeat) && (nums[i] != nums[i + 1]))
            {
                // xsame xsame
                repeat = false;
                nums[nindex] = nums[i];
                ++nindex;
            }
        }
                
        return (nindex);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums{1,2,3,3,5,6,7,7};
    int results  = (new Solution) -> removeDuplicates(nums);
    cout<<results;
    //std::cout << "Hello, World!\n";
    

    return 0;
}
