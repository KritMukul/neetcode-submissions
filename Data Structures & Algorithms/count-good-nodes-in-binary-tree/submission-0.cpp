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
    void dfs(TreeNode* node, int maxi, int &cnt) {
        if(!node) return;
        if(node->val >= maxi) cnt++;
        maxi = max(maxi, node->val);
        dfs(node->left, maxi, cnt);
        dfs(node->right, maxi, cnt);
    }
public:
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        dfs(root, root->val, cnt);
        return cnt;
    }
};
