//
//  main.cpp
//  testing
//
//  Created by Ethan Kho on 7/15/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
using namespace std;
int fibonacci(int n)
{
    //1 1 2 3 5 8 13 21
    if (n == 1)
    {
        return 1;
    }
    else if ( n == 0)
    {
        return 0;
    }
    else
    {
        return (fibonacci(n - 1) + fibonacci(n - 2));
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int results =  fibonacci(2);
    cout<<results;
    return 0;
}
