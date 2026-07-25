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
    int f(TreeNode* node, int & maxi) {
        if(!node) return 0;
        int l = 0, r = 0;
        if(node->left) l = f(node->left, maxi);
        if(node->right) r = f(node->right, maxi);
        maxi = max(maxi, l + r);
        return 1 + max(l, r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        f(root, maxi);
        return maxi;
    }
};
