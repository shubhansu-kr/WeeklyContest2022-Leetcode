// https://leetcode.com/contest/weekly-contest-304/problems/maximum-number-of-groups-entering-a-competition/

// You are given a positive integer array grades which represents the 
// grades of students in a university. You would like to enter all these 
// students into a competition in ordered non-empty groups, such that the 
// ordering meets the following conditions:

// The sum of the grades of students in the ith group is less than the 
// sum of the grades of students in the (i + 1)th group, for all groups 
// (except the last).
// The total number of students in the ith group is less than the total 
// number of students in the (i + 1)th group, for all groups (except the last).
// Return the maximum number of groups that can be formed.

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int i = 1 ;
        while (i <= n) {
            n -= i ;
            ++i;
        }
        return i-1 ;
    }
};

int main () {
    
    return 0;
}