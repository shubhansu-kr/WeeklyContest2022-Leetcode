// 6047. Remove Digit From Number to Maximize Result

// You are given a string number representing a positive integer
// and a character digit.

// Return the resulting string after removing exactly one occurrence
// of digit from number such that the value of the resulting
// string in decimal form is maximized. The test cases are generated
// such that digit occurs at least once in number.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDigit(string number, char digit)
    {
        int ind;
        for (int i = 0; i < number.length() - 1; i++)
        {
            if (number[i] == digit)
            {
                if (number[i + 1] > digit)
                {
                    number.erase(i, 1);
                    return number;
                }
                ind = i;
            }
        }
        if (number.back() == digit)
        {
            number.pop_back();
        }
        else
        {
            number.erase(ind, 1);
        }
        return number;
    }
};

int main()
{

    return 0;
}