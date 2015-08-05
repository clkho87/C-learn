//
//  main.cpp
//  Best time to buy and sell stock
//
//  Created by Ethan Kho on 7/20/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() < 2)
        {
            return 0;
        }
        int min_price = prices[0];
        //int max_price = prices[1];
        //int max_profit = prices[1] - prices[0];
        int max_profit = 0;
        int potential_profit = 0;
        for(auto current = prices.begin() + 1; current != prices.end(); ++current)
        {
            
            potential_profit = *current - min_price;
            max_profit = max(potential_profit, max_profit);
            min_price = min(min_price, *current);
        }
        return max_profit;
    }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //(new Solution) -> maxProfit());
    return 0;
}
