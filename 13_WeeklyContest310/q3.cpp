// https://leetcode.com/contest/weekly-contest-310/problems/longest-increasing-subsequence-ii/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if ((nums[i] > nums[j]) && (nums[i] - nums[j] <= k) && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
        return *max_element(dp.begin(), dp.end());
    }

    int lengthOfLIS(vector<int>& nums, int k) {
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the smallest number >= x
                *it = x; // Replace that number with x
            }
        }
        return sub.size();
    }
};


// class Solution {
// 
//     Tabulation : WA
// public:
//     int lengthOfLIS(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<unordered_map<int, int>> dp(nums.size());

//         for (auto &j: nums)
//         {
//             if ((j - nums[0] <= k) && (nums[0] < j)) dp[0][j] = 1;
//         }
//         for (int i = 1; i < n; ++i)
//         {
//             for (auto &j: nums)
//             {
//                 int pick = -1e9;
//                 if ((j - nums[i] <= k) && (nums[i] < j)){
//                     pick = 1 + dp[i-1][nums[i]];
//                 }
//                 int noPick = dp[i-1][j];

//                 dp[i][j] = max(pick, noPick);
//             }         
//         }
//         int ans = INT_MIN;
//         for(auto &a: dp[n-1]) ans = max(ans, a.second);
//         return ans;
//     }
// };

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int prev = -1;
        vector<unordered_map<int, int>> dp(nums.size());
        return solve(nums, k, dp, prev, nums.size()-1);
    }

    int solve(vector<int> &nums, int &k, vector<unordered_map<int, int>> &dp, int &prev, int i) {
        if (i == 0) {
            if (prev == -1 || ((prev - nums[i] <= k) && (nums[i] < prev))) return 1;
            return 0;
        }

        if (dp[i][prev] != 0) return dp[i][prev];

        int pick = -1e9;
        if (prev == -1 || ((prev - nums[i] <= k) && (nums[i] < prev))){
            pick = 1 + solve(nums, k, dp, nums[i], i-1);
        }
        int noPick = solve(nums, k, dp, prev, i-1);

        return dp[i][prev] = max(pick, noPick);
    }
};

int main () {
    
    return 0;
}