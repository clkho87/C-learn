//
//  main.cpp
//  valid sudoku
//
//  Created by Ethan Kho on 6/9/15.
//  Copyright (c) 2015 Ethan Kho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<char>> row(9, vector<char>(9));
        vector<vector<char>> col(9, vector<char>(9));
        vector<vector<char>> box(9, vector<char>(9));
 
        
        for(int i = 0 * 9 ; i < 9 * 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.') continue;
                if((board[i][j] < '0') || (board[i][j] > '9')) return false;
                
                int number = board[i][j] - '1';
                if(row[i][number] || col[j][number] || box[(i/3) * 3 + j/3][number])
                {
                    return false;
                }
            
                row[i][number] = true;
                col[j][number] = true;
                box[((i/3) * 3 + j/3)][number] =  true;
            }
        }
        return true;
        
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<vector<char>> board(9, vector<char>(9));
    
    int k = - 2;
    for(int i = 0; i < 9; i++)
    {
        k = k + 3;
        if(k > 9)
        {
            k = k % 10 + 1;
        }
        for(int j = 0; j < 9; j++)
        {
            //cout<<(k + '0');
            board[i][j] = (k + '0');
            k++;
            if(k > 9)
            {
                k = k % 10 + 1;
            }
            
        }
    }
    
    for(int i = 0; i < 9; i++)
    {
        cout << "\n";
        for(int j = 0; j < 9; j++)
        {
            //cout<<board[i][j];
            cout<< board[i][j] << ',';
        }
    }
   
    bool result = (new Solution) -> isValidSudoku(board);
    if (result) cout<<"true";
    else cout<<"false";
    return 0;
}
