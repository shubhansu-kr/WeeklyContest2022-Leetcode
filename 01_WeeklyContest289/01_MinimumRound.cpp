// problems/minimum-rounds-to-complete-all-tasks/

// You are given a 0-indexed integer array tasks, where tasks[i] represents the
// difficulty level of a task. In each round, you can complete either 2 or 3 tasks of
// the same difficulty level.

// Return the minimum rounds required to complete all the tasks, or -1 if it is not possible
// to complete all the tasks.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        map<int, int> frequency;
        for (int i = 0; i < tasks.size(); i++)
        {
            frequency[tasks[i]]++;
        }
        int round = 0;
        for (auto it : frequency)
        {
            // it is a pair
            round += (it.second / 3);
            it.second %= 3;
            round += (it.second / 2);
            it.second %= 2;
            if (it.second)
            {
                return -1;
            }
        }
        return round;
    }
};

int main()
{

    return 0;
}