//
//  main.cpp
//  rectangle area
//
//  Created by Ethan Kho on 6/9/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:

    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        //take the middle 2 coordinate
        //get x; from A C E F
        //intersect if the min_first < max_second < max_first or min_second < max_first < max_second;
        int inter_area = 0;
 
        inter_area  = max(min(C,G) - max(A,E), 0) * max(min(D, H) - max(B, F ), 0);
        //cout<<inter_area;
        return (((C-A) * (D-B)) + ((G - E) * (H - F)) - inter_area);
        //calculate the area for both
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    /*
    int a = -3;
    int b = 0;
    int c = 3;
    int d = 4;
    int e = 0;
    int f = -1;
    int g = 9;
    int h = 2;
     */
    int a = -2;int b =  -2; int c = 2; int d =  2;int e = -2; int f = -2; int g = 2; int h = 2;
    int results = (new Solution)-> computeArea(a, b , c , d , e , f , g , h );
    cout<<results;
    std::cout << "Hello, World!\n";
    return 0;
}
