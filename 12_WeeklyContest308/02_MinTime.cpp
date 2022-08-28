// https://leetcode.com/contest/weekly-contest-308/problems/minimum-amount-of-time-to-collect-garbage/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int m=0, p=0, g=0, mI=0, pI = 0, gI = 0;
        for (int i = 0; i < garbage.size(); ++i)
        {
            for (int j = 0; j < garbage[i].size(); ++j)
            {
                if (garbage[i][j] == 'M') ++m, mI = i;
                else if (garbage[i][j] == 'P') ++p, pI = i;
                else ++g, gI = i;  
            }
        }
        int time = 0;
        time += (m + p + g);
        for (int i = 1; i < travel.size(); ++i)
        {
            travel[i] += travel[i-1];
        }
        if (mI) time += travel[mI-1];
        if (gI) time += travel[gI-1];
        if (pI) time += travel[pI-1];

        return time;
    }
};

int main () {
    
    return 0;
}