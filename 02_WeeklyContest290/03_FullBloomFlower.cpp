// 6044. Number of Flowers in Full Bloom

// You are given a 0-indexed 2D integer array flowers, where flowers[i]
// = [starti, endi] means the ith flower will be in full bloom from starti to
// endi (inclusive). You are also given a 0-indexed integer array persons of size
// n, where persons[i] is the time that the ith person will arrive to see the flowers.

// Return an integer array answer of size n, where answer[i] is the number of flowers
// that are in full bloom when the ith person arrives.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Prone to TLE solution
    
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons)
    {
        vector<int> res;
        for (auto it : persons)
        {
            int count = 0;
            for (auto x : flowers)
            {
                if (it >= x[0] && it <= x[1])
                {
                    ++count;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};

int main()
{

    return 0;
}