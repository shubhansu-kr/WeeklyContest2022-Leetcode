// https://leetcode.com/contest/weekly-contest-311/problems/reverse-odd-levels-of-binary-tree/

#include <bits/stdc++.h>
using namespace std ;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        
    }
    void reverse(TreeNode* root, int i = 0) {
        if (!root->left) return;

        if (i % 2 == 0) {
            int temp = root->left->val;
            root->left->val = root->right->val;
            root->right->val = temp;
        }
        reverse(root->left, i+1);
        reverse(root->right, i+1);
    }
};

// class Solution {
// public:
//     TreeNode* reverseOddLevels(TreeNode* root) {
//         reverse(root);
//         return root;
//     }
//     void reverse(TreeNode* root, int i = 0) {
//         if (!root->left) return;

//         if (i % 2 == 0) {
//             int temp = root->left->val;
//             root->left->val = root->right->val;
//             root->right->val = temp;
//         }
//         reverse(root->left, i+1);
//         reverse(root->right, i+1);
//     }
// };

int main () {
    
    return 0;
}