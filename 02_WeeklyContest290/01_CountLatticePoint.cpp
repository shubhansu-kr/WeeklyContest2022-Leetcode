// 6042. Count Lattice Points Inside a Circle

// Given a 2D integer array circles where circles[i] = [xi, yi, ri] represents the
// center (xi, yi) and radius ri of the ith circle drawn on a grid, return the number
// of lattice points that are present inside at least one circle.

// Note:

// A lattice point is a point with integer coordinates.
// Points that lie on the circumference of a circle are also considered to be inside it.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countLatticePoints(vector<vector<int>> &circles)
    {
        int count = 0;
        for (auto a : circles)
        {
            // count for each circle is square + 4
            // find square length
            int l = 2 * (a[1]) - 1;
            count += ((l * l) + 4);
        }
        // Find the common points and subtract
        int common = 1 ;
        // Not possible     
    }
};

int main()
{

    return 0;
}