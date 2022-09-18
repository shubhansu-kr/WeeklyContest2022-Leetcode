// https://leetcode.com/contest/weekly-contest-311/problems/length-of-the-longest-alphabetical-continuous-substring/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 1, i = 1, prev = s[0], len = 1;
        while(i < s.length()) {
            if (s[i] - prev == 1){
                len++;
                prev = s[i];
            }
            else {
                ans = max(ans, len);
                prev = s[i];
                len = 1;
            }
            ++i; 
        } 
        ans = max(ans, len);
        return ans;
    }
};

int main () {
    
    return 0;
}