// https://leetcode.com/contest/weekly-contest-296/problems/min-max-game/

// You are given a 0-indexed integer array nums whose length is a
// power of 2.

// Apply the following algorithm on nums:

// Let n be the length of nums. If n == 1, end the process. Otherwise,
// create a new 0-indexed integer array newNums of length n / 2.
// For every even index i where 0 <= i < n / 2, assign the value of
// newNums[i] as min(nums[2 * i], nums[2 * i + 1]).
// For every odd index i where 0 <= i < n / 2, assign the value of
// newNums[i] as max(nums[2 * i], nums[2 * i + 1]).
// Replace the array nums with newNums.
// Repeat the entire process starting from step 1.
// Return the last number that remains in nums after applying the algorithm.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Brute Force
public:
    int minMaxGame(vector<int> &nums)
    {
        vector<int> newNums;
        while (nums.size() > 1)
        {
            int toggle = 1;
            for (int i = 0; i < nums.size() - 1; ++i)
            {
                if (toggle)
                {
                    newNums.emplace_back(min(nums[i], nums[i + 1]));
                    toggle = 0;
                }
                else
                {
                    newNums.emplace_back(max(nums[i], nums[i + 1]));
                    toggle = 1;
                }
                ++i;
            }
            nums.swap(newNums);
            newNums.clear();
        }
        return nums[0];
    }
};

int main()
{

    return 0;
}