// https://leetcode.com/contest/weekly-contest-311/problems/smallest-even-multiple/ 

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int smallestEvenMultiple(int n) {
        if (n % 2 == 0) return n;
        else return n*2;
    }
};

int main () {
    
    return 0;
}