// https://leetcode.com/contest/weekly-contest-310/problems/divide-intervals-into-minimum-number-of-groups/

#include <bits/stdc++.h>
using namespace std;


// WA
// class Solution
// {
// public:
//     int minGroups(vector<vector<int>> &intervals)
//     {
//         vector<int> visited(intervals.size(), 0);
//         // 0 for unvisited, 1 for visited
//         int flag = 1, ans = 0;
//         while(flag){
//             flag = 0;
//             ++ans;
//             int st = INT_MAX, ed = INT_MIN;
//             for (int i = 0; i < intervals.size(); ++i)
//             {
//                 if(!visited[i]) {
//                     flag = 1;
//                     if(intervals[i][1] > ed) {
//                         ed = intervals[i][1];
//                         st = intervals[i][0];
//                         visited[i] = 1;
//                     }
//                     if (intervals[i][0] < st) {
//                         st = intervals[i][0];
//                     }
//                 }
//             }
//         }
//         return ans-1;
//     }
// };

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &v1, vector<int> &v2)
             { return v1[0] < v2[0]; });
        vector<int> visited(intervals.size(), 0);
        // 0 for unvisited, 1 for visited
        int flag = 1, ans = 0;
        while(flag){
            flag = 0;
            ++ans;
            int st = INT_MIN;
            for (int i = 0; i < intervals.size(); ++i)
            {
                if(!visited[i]) {
                    flag = 1;
                    if(intervals[i][0] > st) {
                        st = intervals[i][1];
                        visited[i] = 1;
                    }
                }
            }
        }
        return ans-1;
    }
};

int main()
{

    return 0;
}