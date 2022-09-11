// https://leetcode.com/contest/weekly-contest-310/problems/optimal-partition-of-string/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // "gizfdfri"
public:
    int partitionString(string s) {
        int count = 0;
        int i = 0;
        while (i < s.length()) {
            unordered_set<char> check;
            ++count;
            check.insert(s[i++]);
            if (i > s.length()) break;
            while(!check.count(s[i])){
                check.insert(s[i]);
                ++i;
            }
            check.clear();            
        }
        return count;
    }
};

int main () {
    
    return 0;
}