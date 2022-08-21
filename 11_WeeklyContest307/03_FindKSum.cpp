// https://leetcode.com/contest/weekly-contest-307/problems/find-the-k-sum-of-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // WA 
public:
    bool sortcol(const vector<long long> &v1, const vector<long long> &v2)
    {
        return v1[0] > v2[0];
    }

    long long kSum(vector<int> &nums, int k)
    {
        vector<vector<long long>> dp;
        subSeq(dp, nums);
        sort(dp.begin(), dp.end(), sortcol);
        return dp[k - 1][1];
    }

    void subSeq(vector<vector<long long>> &dp, vector<int> &nums, long long sum = 0, int len = 0, int i = 0)
    {
        if (i == nums.size())
        {
            dp.push_back({len, sum});
            return;
        }

        sum += nums[i];
        subSeq(dp, nums, sum, len + 1, i + 1);
        sum -= nums[i];

        subSeq(dp, nums, sum, len, i + 1);
    }
};

int main()
{

    return 0;
}