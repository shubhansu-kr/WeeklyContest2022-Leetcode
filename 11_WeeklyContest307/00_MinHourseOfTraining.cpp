// https://leetcode.com/contest/weekly-contest-307/problems/minimum-hours-of-training-to-win-a-competition/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // 5
    // 3
    // [1,4,3,2]
    // [2,6,3,1]
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
    {
        int eng = 0, exp = 0;
        for (int i = 0; i < energy.size(); ++i)
        {
            if (initialEnergy > energy[i])
            {
                initialEnergy -= energy[i];
            }
            else
            {
                eng += energy[i] - initialEnergy + 1;
                initialEnergy = 1;
            }

            if (initialExperience > experience[i])
            {
                initialExperience += experience[i];
            }
            else
            {
                exp += experience[i] - initialExperience + 1;
                initialExperience = experience[i] * 2 + 1;
            }
        }
        return exp + eng;
    }
};

int main()
{

    return 0;
}