//
//  main.cpp
//  isAnagram
//
//  Created by Ethan Kho on 8/2/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())
        {
            return false;
        }
        
        int size  = (int)s.size();
        unordered_map<int, int> m;
        for(int i = 0; i < size; i++)
        {
            int j = s[i] - 'a';
            m[j] = m[j] + 1;
        }
        
        for(int i = 0; i < size; i++)
        {
            int j = t[i] - 'a';
            if(m[j] == 0)
            {
                return false;
            }
            else
            {
                m[j] = m[j] - 1;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string s = "wassup";
    string m = "pussaw";
    bool check = (new Solution) -> isAnagram(s, m);
    if(check) cout<<"true";
    else cout<< "false";
    return 0;
}
