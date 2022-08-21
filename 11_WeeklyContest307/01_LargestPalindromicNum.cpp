// https://leetcode.com/contest/weekly-contest-307/problems/largest-palindromic-number/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // WA : Return the largest Possible number 
public:
    string largestPalindromic(string num) {
        vector<int> m(10, 0);
        for (int i = 0; i < num.length(); ++i)
        {
            m[num[i]-'0']++;
        }
        int len = 0, mOdd = 0, oddInd = -1, flag = 0;
        for (int i = 1; i < 10; ++i)
        {
            if (m[i] % 2){
                mOdd = max(mOdd, m[i]);
                oddInd = i;
            }
            else {
                if (m[i]) {
                    len += m[i];
                    flag = 1;
                }
            }
        }
        cout << len << " " << mOdd << " " << oddInd << " " << flag << endl; 
        if (m[0] % 2 && flag) {
            if (m[0] > mOdd) {
                oddInd = 0;
                mOdd = m[0];
            }
        }
        else {
            if (flag) {
                len += m[0];
            }
        }
        cout << len << " " << mOdd << " " << oddInd << " " << flag << endl; 
        if (oddInd != -1) {
            len += mOdd;
        }
        cout << len << " " << mOdd << " " << oddInd << " " << flag << endl; 
        if (len == 0) return "";
        string ans(len, '#');
        int i = 0;
        for (int j = 9; j >= 0; --j)
        {
            if (j == 0 && flag == 0) continue;
            if (m[j] % 2 == 0) {
                while(m[j]){
                    ans[i] = ans[len-1-i] = '0' + j;
                    m[j] -= 2;
                    ++i;
                }
            }
        }
        while (mOdd > 0) {
            ans[i] = ans[len-i-1] = '0' + oddInd;
            ++i;
            mOdd -= 2 ;
        }
        return ans;
    }
};

int main () {
    Solution obj;
    string s = "00090";

    cout << obj.largestPalindromic(s);
    return 0;
}