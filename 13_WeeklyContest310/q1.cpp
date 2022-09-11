// https://leetcode.com/contest/weekly-contest-310/problems/most-frequent-even-element/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> freq;
        for(auto &a: nums){
            if (a % 2 == 0) freq[a]++;
        }
        int ans = -1, maxi=INT_MIN;
        for (auto &a: freq){
            if (a.second > maxi) {
                ans = a.first;
                maxi = a.second;
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}