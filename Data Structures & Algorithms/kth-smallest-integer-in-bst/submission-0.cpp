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
    void dfs(TreeNode* node, int& k, int& cnt, int& ans) {
        if(node->left) dfs(node->left, k, cnt, ans);
        cnt++;
        if(cnt == k) ans = node->val;
        if(node->right) dfs(node->right, k, cnt, ans);
        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, ans;
        dfs(root, k, cnt, ans);
        return ans;
    }
};
