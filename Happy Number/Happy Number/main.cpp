//
//  main.cpp
//  Happy Number
//
//  Created by Ethan Kho on 8/3/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int rem = 0;
        int result = n;
        while(result != 1)
        {
            if(result == 4) return false;
            if (result == 1) return true;
            n = result;
            result  = 0;
            //cout<< n <<"\n";
            while (n != 0)
            {
                rem  =  n % 10;
                n  = n/10;
                result = pow(rem,2) + result;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    //int n =  pow(2,3);
    //cout<< n;
    bool check = (new Solution) ->isHappy(3);
    if(check) cout<<"true";
    else cout<< "false";
    
    return 0;
}
