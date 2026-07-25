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
    void f(TreeNode* node, int & maxi, int d) {
        if(!node) return;
        maxi = max(maxi, d);
        f(node->left, maxi, d+1);
        f(node->right, maxi, d+1);
    }
public:
    int maxDepth(TreeNode* root) {
        int maxi = 0;
        f(root, maxi, 1);
        return maxi;
    }
};
