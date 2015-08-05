//
//  main.cpp
//  fibonacci
//
//  Created by Ethan Kho on 6/9/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
using namespace std;

//fibonacci  0 1 1 2 3 5 8 13 21 34 55
int fib(int n)
{
    if(n<=1)
    {
        return n;
    }
    else
    {
        return fib(n-1) + fib(n-2);
    }
}

int fib_iter(int n)
{
    int *array =  new int[n +1];
    array[0] = 0;
    array[1] = 1;
    for(int i = 2; i<=n+1; i++)
    {
        array[i] = array[i - 1] +  array[i -2];
    }
    return array[n];
}

int fib_niter(int n)
{
    if(n <= 1)
    {
        return n;
    }
    int first = 0; int second = 1;int current = 0;
    //compute the last 2
    for(int i = 2; i <= n; i++)
    {
        current = first + second;
        first = second;
        second = current;
        //cout<<'*'<<current;
    }
    return current;
    
}
int main ()
{
    int n = 9;
    printf("%d", fib(n));
    cout<<"\n";
    printf("%d", fib_iter(n));
    cout<<"\n"<<fib_niter(n);
    return 0;
}