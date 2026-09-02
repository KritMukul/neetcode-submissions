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
    int preIn = 0, inIn = 0;
    TreeNode* build(vector<int>& pre, vector<int>& in, int lim) {
        if(preIn >= pre.size()) return nullptr;
        if(in[inIn] == lim) {
            inIn++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[preIn++]);
        root->left = build(pre, in, root->val);
        root->right = build(pre, in, lim);
        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, INT_MAX);
        
    }
};
