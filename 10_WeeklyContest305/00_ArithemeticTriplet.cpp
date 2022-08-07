// https://leetcode.com/contest/weekly-contest-305/problems/number-of-arithmetic-triplets/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        unordered_set<int> track(nums.begin(), nums.end());
        int count = 0;
        for (int i = nums.size() - 2; i > 0; --i)
        {
            if (track.count(nums[i] - diff) && track.count(nums[i] + diff))
                ++count;
        }
        return count ;
    }
};

int main()
{

    return 0;
}