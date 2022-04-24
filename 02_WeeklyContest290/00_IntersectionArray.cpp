// 6041. Intersection of Multiple Arrays

// Given a 2D integer array nums where nums[i] is a non-empty
// array of distinct positive integers, return the list of integers
// that are present in each array of nums sorted in ascending order.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<vector<int>> &nums)
    {
        set<int> p;
        for (int i = 0; i < nums[0].size(); i++)
        {
            p.insert(nums[0][i]);
        }

        for (int i = 1; i < nums.size(); i++)
        {
            for (auto a : p)
            {
                if (find(nums[i].begin(), nums[i].end(), a) == nums[i].end())
                {
                    p.erase(a);
                }
            }
        }
        vector<int> res(p.begin(), p.end());
        return res;
    }
};

int main()
{

    return 0;
}