// https://leetcode.com/contest/weekly-contest-295/problems/rearrange-characters-to-make-target-string/

// You are given two 0-indexed strings s and target.
// You can take some letters from s and rearrange them to form
// new strings.

// Return the maximum number of copies of target that can be
// formed by taking letters from s and rearranging them.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rearrangeCharacters(string s, string target)
    {
        unordered_map<char, int> freq;
        for (char a : s)
        {
            ++freq[a];
        }
        int count = 0, flag = 0;
        while (true)
        {
            for (char a : target)
            {
                if (freq[a])
                {
                    --freq[a];
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
            ++count;
        }
        return count;
    }
};

int main()
{

    return 0;
}