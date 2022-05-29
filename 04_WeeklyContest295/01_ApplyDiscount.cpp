// https://leetcode.com/contest/weekly-contest-295/problems/apply-discount-to-prices/

// A sentence is a string of single-space separated words where each word
// can contain digits, lowercase letters, and the dollar sign '$'. A word
// represents a price if it is a non-negative real number preceded by a dollar sign.

// For example, "$100", "$23", and "$6.75" represent prices while "100",
// "$", and "2$3" do not.
// You are given a string sentence representing a sentence and an integer
// discount. For each word representing a price, apply a discount of
// discount% on the price and update the word in the sentence. All
// updated prices should be represented with exactly two decimal places.

// Return a string representing the modified sentence.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Runtime Error
public:
    string discountPrices(string sentence, int discount)
    {
        string s;
        float price;
        int ind, len = 0, flag = 0;
        for (int i = 0; i < sentence.length(); ++i)
        {
            if (sentence[i] == ' ')
            {
                flag = 0;
                s = sentence.substr(ind, len);
                price = stof(s);
                price = (100 - discount) / 100 * price;

                stringstream stream;
                stream << fixed << setprecision(2) << price;
                s = stream.str();
                sentence.insert(ind, s);
                i += (s.length() - len);
                len = 0;
            }
            else if (sentence[i] == '$')
            {
                if (i > 0 && sentence[i - 1] != ' ')
                {
                    flag = 0;
                }
                else
                {
                    flag = 1;
                    ind = i + 1;
                }
            }
            if (flag)
            {
                if (sentence[i] >= '0' && sentence[i] <= '9')
                {
                    ++len;
                }
                else
                {
                    flag = 0;
                }
            }
        }
        return sentence;
    }
};

int main()
{

    return 0;
}