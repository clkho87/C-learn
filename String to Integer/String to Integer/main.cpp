//
//  main.cpp
//  String to Integer
//
//  Created by Ethan Kho on 6/9/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include <String>
using namespace std;
//it will come with -
class Solution {
public:
    int myAtoi(string str){
        int index = 0;
        int pos = true;
        long int result = 0;
        int i = 0;
        while(str[index] == ' ')++index;
        if(str[index] == '-')
        {
            pos = false;
            index++;
        }
        else if(str[index] == '+')
        {
            pos = true;
            index++;
        }
        else if(str[index] < '0' || str[index] > '9')
        {
            return 0;
        }
        
        while(index < str.size())
        {
            if(str[index] < '0' || str[index] > '9')
            {
                break;
            }
            
            if(str[index] >= '0' && str[index] <= '9')
            {
                result = result * 10;
                result = result + (str[index] - '0');
                ++i;
                ++index;
                if(i > 10)
                {
                    if(pos)
                    {
                        cout<<"here";
                        return INT_MAX;
                    }
                    else
                    {
                        cout<<"here";
     
                        return INT_MIN;
                    }
                }
             }
        }
        
        if(pos)
        {
            if(result > INT_MAX)
            {
                cout<<"here";
                return INT_MAX;
                
            }
            else
            {
                cout<<"here";
                return result;
            }
        }
        else
        {
            if(-result < INT_MIN)
            {
                cout<<"here";
                return INT_MIN;
            }
            else
            {
                cout<<"here";
                return (-1 * result);
            }
        }
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    string s =  "-2147483649";
    int results = (new Solution) -> myAtoi(s);
    cout<< results;
   // std::cout << "Hello, World!\n";
    return 0;
}
