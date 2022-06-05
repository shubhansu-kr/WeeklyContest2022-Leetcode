// https://leetcode.com/contest/weekly-contest-296/problems/replace-elements-in-an-array/

// You are given a 0-indexed array nums that consists of n distinct positive
// integers. Apply m operations to this array, where in the ith operation you
// replace the number operations[i][0] with operations[i][1].

// It is guaranteed that in the ith operation:

// operations[i][0] exists in nums.
// operations[i][1] does not exist in nums.
// Return the array obtained after applying all the operations.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations)
    {
        // Remember the index
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            m[nums[i]] = i;
        }
        for (int i = 0; i < operations.size(); ++i)
        {
            nums[m[operations[i][0]]] = operations[i][1];
            m[operations[i][1]] = m[operations[i][0]] ;
        }
        return nums;
    }
};

class Solution
{
    // Using hashmap - Wrong answer
    // [1,2]
    // [[1,3],[2,1],[3,2]]
    // Operation can be done after intro to new ones
public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations)
    {
        unordered_map<int, int> m;

        for (int i = 0; i < operations.size(); ++i)
        {
            m[operations[i][0]] = operations[i][1];
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (m[nums[i]])
            {
                nums[i] = m[nums[i]];
            }
        }
        return nums;

        // for (auto &a : operations)
        //     m[a[0]] = m[a[1]];
        // for (int i = 0; i < nums.size(); ++i)
        //     if (m[nums[i]])
        //         nums[i] = m[nums[i]];
        // return nums;
    }
};

class Solution
{
    // BruteForce will give tle
public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations)
    {
        for (int i = 0; i < operations.size(); ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
            {
                if (operations[i][0] == nums[j])
                {
                    swap(nums[j], operations[i][1]);
                    break;
                }
            }
        }
        return nums;
    }
};

int main()
{

    return 0;
}