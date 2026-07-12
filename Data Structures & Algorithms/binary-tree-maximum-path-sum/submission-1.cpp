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
    int trav(TreeNode* node, int &maxi) {
        int l = 0, r = 0;
        if(node->left) l = max(l, trav(node->left, maxi));
        if(node->right) r = max(r, trav(node->right, maxi));
        maxi = max(maxi, l+r+node->val);
        return node->val + max(l, r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        trav(root, maxi);
        return maxi;
    }
};
