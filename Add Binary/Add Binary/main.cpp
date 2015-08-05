//
//  main.cpp
//  Add Binary
//
//  Created by Ethan Kho on 6/15/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    string addBinary(string a, string b) {
        //have to know which one has larger size
        string big, small, result;
        if(a.length() >= b.length())
        {
            big = a; // a always bigger is the same
            small = b;
        }
        else
        {
            big = b;
            small =  a;
        }
        
        // put the max and min accordingly

        if(big.length() > small.length())
        {
            int diff = (big.length() - small.length());
            for(int i = 0; i < diff; i++)
            {
        
                small = '0' + small;
                
                
            }
        }
    
        //pad the one that has shorter string with 0
        
        
        // change to integer and add them together
        int carry = 0;
        for(int i = (big.length() - 1); i >= 0; i--)
        {
            int resultint = 0;
            int bigint = big[i] - '0';
            int smallint = small[i] - '0';
            resultint =  bigint + smallint + carry;
            //divide for msb // rem for lsb
            int rem = resultint % 2;
            carry = resultint/2;
            char rem_str = rem + '0';
            result = rem_str + result;
        }
        // find the carry and remainder
        // change back to string
        if(carry)
        {
            return ('1' + result);
        }
        else
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string a = "100";
    string b = "110010";
    string result = (new Solution) -> addBinary(a, b);
    cout<< result;
    return 0;
}
