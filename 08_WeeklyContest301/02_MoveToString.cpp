// https://leetcode.com/contest/weekly-contest-301/problems/move-pieces-to-obtain-a-string/

// You are given two strings start and target, both of length n. Each string 
// consists only of the characters 'L', 'R', and '_' where:

// The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the 
// left only if there is a blank space directly to its left, and a piece 'R' can 
// move to the right only if there is a blank space directly to its right.
// The character '_' represents a blank space that can be occupied by any of the 
// 'L' or 'R' pieces.
// Return true if it is possible to obtain the string target by moving the pieces 
// of the string start any number of times. Otherwise, return false.


#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0;
        while (i < start.size() && j < start.size()) {
            if (start[i] == target[j]) ++i, ++j; continue;
            if (target[i] == 'L' || target[j] == 'R' || (target[i] == 'R' && target[j] == 'L')) return false;

            int ind = i + 1;
            if (start[i] == '_') {
                while (ind < start.size()) {
                    if (start[ind] == 'L') {
                        
                    }
                    ++ind;
                }
            }
            else if (start[i] == 'R') {

            }
            
        }
        return true;
    }
};

int main () {
    
    return 0;
}