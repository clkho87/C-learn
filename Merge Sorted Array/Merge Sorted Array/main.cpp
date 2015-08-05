//
//  main.cpp
//  Merge Sorted Array
//
//  Created by Ethan Kho on 5/29/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = m-1;
        int index2 = n-1;
        int fullindex = m+n-1;
        while(index1 >= 0  || index2 >= 0)
        {
            if(index1<0)
            {
                nums1[fullindex] = nums2[index2];
                fullindex--;
                index2--;
                continue;
            }
            
            if(index2<0)
            {
                nums1[fullindex] = nums1[index1];
                fullindex -- ;
                index1--;
                continue;
            }
            if(nums1[index1] > nums2[index2])
            {
                nums1[fullindex] = nums1[index1];
                index1--;
                fullindex--;
                continue;
            }
            else if(nums1[index1] <= nums2[index2])
            {
                nums1[fullindex] = nums2[index2];
                fullindex--;
                index2--;
                continue;
            }

        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int m = 1;
    int n = 0;
    //int myints[] = {1,3,4,6,7,8,9,29,30,57};
    int myints[] = {1};

    vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
    fifth.resize(m+n);
    //int myints2[] = {2,5,7,9,23,66,29};
    int myints2[0];
    vector<int> fifth2 (myints2, myints2 + sizeof(myints2) / sizeof(int) );
    (new Solution)->merge(fifth, m, fifth2, n);
    for(int i = 0; i < (m+n); i++)
    {
        cout<<fifth[i]<<",";
    }
    return 0;
}
