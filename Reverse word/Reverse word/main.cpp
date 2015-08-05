//
//  main.cpp
//  Reverse word
//
//  Created by Ethan Kho on 6/8/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    //reverse all sentence
    // trim out all the spaces
    //reverse word by word
    
    void reverseSentence(string &s)
    {
        int i = 0;
        int j = (int)(s.size() - 1);
        while(i<j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            ++i; --j;
        }
        //cout<<s;
    }
    
    int first_non_empty_index(string &s)
    {
        int count = 0;
        
        for(int i = 0; i<s.size();i++ )
        {
            if(s[i] != ' ')
            {
                return count;
            }
            else
            {
                count++;
            }
        }
        return count;
    }
    void trim(string &s)
    {

        int size =  (int)s.size();
        bool sub_duplicate =  false;
        int shift_left = 0;
        
        int trail_zero = first_non_empty_index(s);
       // cout<< trail_zero;
        int index = trail_zero;
        while(index < size)
        {
        
                if((s[index] == ' ') && !sub_duplicate)
                {
                    sub_duplicate = true;
                    s[index - shift_left - trail_zero] = s[index];
                    index++;
                }
                else if((s[index] == ' ') && sub_duplicate)
                {
                    shift_left++;
                    index++;
                    
                }
                else if((s[index] != ' '))
                {
                    sub_duplicate = false;
                    if(shift_left || trail_zero)
                    {
                        s[index - shift_left - trail_zero] = s[index];
                    }
        
                    index++;
                }
        }

        s.resize(s.size() - shift_left - trail_zero);
        if(s[s.size()-1] == ' ')
        {
            s.resize(s.size() - 1);
        }
        //cout<<s;
    }

    void reverse(string &s)
    {
        int current_index = 0;
        int initial_index = 0;
       // while(current_index < s.size())
        while(s[current_index] != '\0')
        {
            //check the first space
            if((s[current_index] != ' '))
            {
                current_index++;
            }
            else
            {
                int i = initial_index;
                int j = current_index -1;
                //current_index++;
 
                while(i < j)
                {
                    //swap it
                    char temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                    i++;
                    j--;
                }
                
                current_index++;
                initial_index = current_index;
                //found the space
                
            }
            //repeat
        }
        
        int i = initial_index;
        int j = current_index -1;
        //current_index++;
        
        while(i < j)
        {
            //swap it
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        
    }
    
    void reverseWords(string &s) {
        //reverse all sentence
        // trim out all the spaces
        //reverse word by word
        reverseSentence(s);
        trim(s);
        reverse(s);
        //cout<<s;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "something is wrong maybe    ";
    
    cout<<"!!";
    (new Solution) -> reverseSentence(s);
    (new Solution) ->  trim(s);
    (new Solution) ->  reverse(s);
    cout<<s;
    //(new Solution) ->  reverseWords(s);
    //cout<<s;
   // int results = (new Solution) ->  first_non_empty_index(s);
   // cout<<results;
    cout<<"!!!";
    //cout << "Hello, World!\n";
    return 0;
}
