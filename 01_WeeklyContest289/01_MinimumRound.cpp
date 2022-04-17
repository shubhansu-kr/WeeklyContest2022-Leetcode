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
    // Wrong answer 
    // [66,66,63,61,63,63,64,66,66,65,66,65,61,67,68,66,62,67,61,64,66,60,69,66,65,68,63,60,
    // 67,62,68,60,66,64,60,60,60,62,66,64,63,65,60,69,63,68,68,69,68,61]
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
            if (it.second % 3 == 0)
            {
                round += (it.second / 3);
                continue;
            }
            else
            {
                if ((it.second % 3) == 2)
                {
                    round += it.second / 3 + 1;
                    continue;
                }
                else
                {
                    if (it.second % 2 == 0)
                    {
                        round += it.second / 2;
                        continue;
                    }
                    else
                    {
                        return -1;
                    }
                }
            }
        }
        return round;
    }
};

class Solution
{
    // Wrong solution : order of evaluation wrong
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