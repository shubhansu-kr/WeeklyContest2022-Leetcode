// https://leetcode.com/contest/weekly-contest-304/problems/make-array-zero-by-subtracting-equal-amounts/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int sub = 0, op = 0;
        sort(nums.begin(), nums.end());

        // val = val - sub ;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!(nums[i]-sub)) continue;
            ++op;
            sub += (nums[i]-sub);
        }
        return op;
    }
};

int main () {
    
    return 0;
}