// 6043. Count Number of Rectangles Containing Each Point

// You are given a 2D integer array rectangles where rectangles[i] = [li, hi]
// indicates that ith rectangle has a length of li and a height of hi. You
// are also given a 2D integer array points where points[j] = [xj, yj] is a
// point with coordinates (xj, yj).

// The ith rectangle has its bottom-left corner point at the coordinates
// (0, 0) and its top-right corner point at (li, hi).

// Return an integer array count of length points.length where count[j]
// is the number of rectangles that contain the jth point.

// The ith rectangle contains the jth point if 0 <= xj <= li and
// 0 <= yj <= hi. Note that points that lie on the edges of a rectangle
// are also considered to be contained by that rectangle.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Time Limit Exceeded :(
public:
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points)
    {
        vector<int> res;
        for (auto a : points)
        {
            int count = 0;
            for (auto b : rectangles)
            {
                if (a[0] <= b[0] && a[1] <= b[1])
                {
                    count++;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};

class Solution
{
    // Time Limit Exceeded :(
public:
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points)
    {
        vector<int> res;
        for (auto a : points)
        {
            int count = 0;
            for (auto b : rectangles)
            {
                if (a[0] <= b[0] && a[1] <= b[1])
                {
                    count++;
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