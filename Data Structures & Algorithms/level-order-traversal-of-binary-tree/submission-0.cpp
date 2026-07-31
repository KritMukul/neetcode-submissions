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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root) q.push(root);
        vector<vector<int>> ans;
        vector<int> temp;
        int size;
        while(!q.empty()) {
            size = q.size();
            temp.assign({});
            while(size--) {
                TreeNode* n = q.front();
                q.pop();
                temp.push_back(n->val);
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
