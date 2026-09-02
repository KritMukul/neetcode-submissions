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
    bool help(TreeNode* node, int mini, int maxi) {
        if(mini != INT_MIN && node->val <= mini || maxi != INT_MAX && node->val >= maxi) return false;
        if(node->left) if(!help(node->left, mini, node->val)) return false;
        if(node->right) if(!help(node->right, node->val, maxi)) return false;

        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return help(root, INT_MIN, INT_MAX);
    }
};
