// https://leetcode.com/contest/weekly-contest-297/problems/calculate-amount-paid-in-taxes/

// You are given a 0-indexed 2D integer array brackets where
// brackets[i] = [upperi, percenti] means that the ith tax bracket
// has an upper bound of upperi and is taxed at a rate of percenti.
// The brackets are sorted by upper bound (i.e. upperi-1 < upperi
// for 0 < i < brackets.length).

// Tax is calculated as follows:

// The first upper0 dollars earned are taxed at a rate of percent0.
// The next upper1 - upper0 dollars earned are taxed at a rate of percent1.
// The next upper2 - upper1 dollars earned are taxed at a rate of percent2.
// And so on.
// You are given an integer income representing the amount of money you earned. Return the amount of money that you have to pay in taxes. Answers within 10-5 of the actual answer will be accepted.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double calculateTax(vector<vector<int>> &brackets, int income)
    {
        double tax = 0;
        int amount;
        for (int i = 0; i < brackets.size() && income > 0; ++i)
        {
            if (i == 0)
            {
                amount = min(income, brackets[i][0]);
                tax += (brackets[i][1] / 100 * amount);
                income -= amount;
            }
            else
            {
                amount = brackets[i][0] - brackets[i - 1][0];
                amount = min(amount, income);
                tax += (brackets[i][1] / 100 * amount);
                income -= amount;
            }
        }
        return tax;
    }
};

int main()
{

    return 0;
}