/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    pair<bool, int> f(TreeNode* node) {
        if(!node) return {true, 0};
        auto l = f(node->left);
        if(!l.first) return {false, 0};
        auto r = f(node->right);
        if(!r.first) return {false, 0};
        if(abs(l.second - r.second) > 1) return {false, 0};
        return {true, 1+max(l.second, r.second)};
    }
public:
    bool isBalanced(TreeNode* root) {
        return f(root).first;
    }
};
