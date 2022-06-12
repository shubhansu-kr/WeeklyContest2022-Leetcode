// https://leetcode.com/contest/weekly-contest-297/problems/minimum-path-cost-in-a-grid/

// You are given a 0-indexed m x n integer matrix grid consisting of distinct integers
// from 0 to m * n - 1. You can move in this matrix from a cell to any other cell in
// the next row. That is, if you are in cell (x, y) such that x < m - 1, you can move
// to any of the cells (x + 1, 0), (x + 1, 1), ..., (x + 1, n - 1). Note that it is not
// possible to move from cells in the last row.

// Each possible move has a cost given by a 0-indexed 2D array moveCost of size (m * n)
// x n, where moveCost[i][j] is the cost of moving from a cell with value i to a cell in
// column j of the next row. The cost of moving from cells in the last row of grid can be
// ignored.

// The cost of a path in grid is the sum of all values of cells visited plus the sum of
// costs of all the moves made. Return the minimum cost of a path that starts from any
// cell in the first row and ends at any cell in the last row.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int mini = INT_MAX;
        for (int x = 0; x < n; ++x)
        {
            dp[m-1][x] = solve(grid, moveCost, dp, m-1, x);
            mini = min(mini, dp[m-1][x]);
        }
        return mini;
    }
    int solve(vector<vector<int>> &grid, vector<vector<int>> &moveCost, vector<vector<int>> &dp, int i, int j)
    {
        // Base condition
        if (i == 0)
        {
            return grid[i][j];
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int work = grid[i][j], temp=0, mini=INT_MAX;
        for (int x = 0; x < grid[0].size(); ++x)
        {
            temp = moveCost[grid[i-1][x]][j] + solve(grid, moveCost, dp, i-1, x);
            work += temp;
            mini = min(mini, work);
        }
        return dp[i][j] = mini;
    }
};

int main()
{

    return 0;
}