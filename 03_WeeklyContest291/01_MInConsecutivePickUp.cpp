// 6048. Minimum Consecutive Cards to Pick Up

// You are given an integer array cards where cards[i] represents
// the value of the ith card. A pair of cards are matching if the
// cards have the same value.

// Return the minimum number of consecutive cards you have to pick
// up to have a pair of matching cards among the picked cards. If
// it is impossible to have matching cards, return -1.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Pick up card in same sequence 
    // TLE 
public:
    int minimumCardPickup(vector<int> &cards)
    {
        int minC = INT_MAX;
        for (int i = 0; i < cards.size(); i++)
        {
            for (int j = i + 1; j < cards.size(); j++)
            {
                if (cards[i] == cards[j])
                {
                    minC = min(minC, (j - i + 1));
                    break;
                }
            }
        }
        if (minC == INT_MAX)
        {
            return -1;
        }
        return minC;
    }
};

int main()
{

    return 0;
}