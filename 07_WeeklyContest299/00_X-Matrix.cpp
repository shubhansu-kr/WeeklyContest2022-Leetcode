// https://leetcode.com/contest/weekly-contest-299/problems/check-if-matrix-is-x-matrix/

// A square matrix is said to be an X-Matrix if both of the following 
// conditions hold:

// All the elements in the diagonals of the matrix are non-zero.
// All other elements are 0.
// Given a 2D integer array grid of size n x n representing a square 
// matrix, return true if grid is an X-Matrix. Otherwise, return false.


#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (j == i || j == (n-1-i)){
                    if (grid[i][j] == 0) return false ;
                }
                else {
                    if (grid[i][j] != 0) return false ;
                }
            }
        }
        return true; 
    }
};

int main () {
    
    return 0;
}