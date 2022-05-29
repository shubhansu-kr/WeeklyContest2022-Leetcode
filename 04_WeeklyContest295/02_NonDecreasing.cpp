// https://leetcode.com/contest/weekly-contest-295/problems/steps-to-make-array-non-decreasing/

// You are given a 0-indexed integer array nums. In one step, remove
// all elements nums[i] where nums[i - 1] > nums[i] for all 0 < i < nums.length.

// Return the number of steps performed until nums becomes a non-decreasing array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalSteps(vector<int> &nums)
    {
        vector<int> temp;
        int count = 0, flag = 0;
        int k = nums[0];
        while (nums.size() > 1)
        {
            flag = 1;
            temp.emplace_back(k);
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] > k)
                {
                    temp.emplace_back(k);
                    flag = 0;
                }
            }
            if (flag)
            {
                break;
            }
            else
            {
                ++count;
                nums.swap(temp);
                temp.clear();
            }
        }
        return count ;
    }
};

int main()
{

    return 0;
}