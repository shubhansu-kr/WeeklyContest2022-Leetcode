// https://leetcode.com/contest/weekly-contest-301/problems/minimum-amount-of-time-to-fill-cups/

// You have a water dispenser that can dispense cold, warm, and hot water.
// Every second, you can either fill up 2 cups with different types of water,
// or 1 cup of any type of water.
// You are given a 0-indexed integer array amount of length 3 where
// amount[0], amount[1], and amount[2] denote the number of cold, warm,
// and hot water cups you need to fill respectively. Return the minimum
// number of seconds needed to fill up all the cups.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fillCups(vector<int> &amount)
    {
        int count = 0, ind;
        while (amount[0] || amount[1] || amount[2])
        {
            if (amount[0] <= amount[1] && amount[0] <= amount[2]) ind = 0;
            else if (amount[1] <= amount[0] && amount[1] <= amount[2]) ind = 1;
            else ind = 2;

            for (int i = 0; i < 3; ++i){if (ind == i || amount[i] == 0) continue;--amount[i];}
            ++count;
        }
        return count;
    }
};

int main()
{

    return 0;
}