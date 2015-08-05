//
//  main.cpp
//  Excel Sheet Column Number
//
//  Created by Ethan Kho on 8/2/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
using namespace std;
#include <math.h>

class Solution {
public:
    int titleToNumber(string s) {
        
        int size =  (int)s.size();
        if(size < 0)
        {
            return 0;
        }
        int count = 0;
        for(int i = 0 ; i < size; i++)
        {
            int j = s[i] - 'A' + 1;
            int index  = size  - i - 1;
            if(index > 0)
            {
                j = j*pow(26,index);
            }
            count  = count + j;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "AAA";
    int check = (new Solution) -> titleToNumber(s);
    cout<<"checking = "<< check;
    return 0;
}
