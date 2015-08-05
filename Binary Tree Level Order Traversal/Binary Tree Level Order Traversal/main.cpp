//
//  main.cpp
//  Binary Tree Level Order Traversal
//
//  Created by Ethan Kho on 8/3/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    //vector <vector <int>> vec(size, vector<int>(size));
    int test = 5;
    int temp = test;
    int check = 0;
    int reverse = 0;
    for(int i = 0; i< sizeof(int) * 8; i++)
    {
        check = temp & 0x01;
        if (check)
        {
            reverse = reverse << 1;
            reverse = reverse | 0x01;
        }
        else
        {
            reverse = reverse << 1;
        }
        temp = temp>> 1;
    }
    cout << bitset<32> (test)<< "\n";
    cout << bitset<32> (reverse);
    
    check = reverse ^ test;
    if(!check)
    {
        cout<< "it is palindrome \n";
    }
    else
    {
        cout<<" it is not \n";
    }
    return 0;
}
