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
    bool check(TreeNode* t1, TreeNode* t2) {
        queue<TreeNode*> q1, q2;
        q1.push(t1);
        q2.push(t2);

        while(!q1.empty() && !q2.empty()) {
            TreeNode* n1 = q1.front(), *n2 = q2.front();
            q1.pop();
            q2.pop();
            if(n1 == NULL ^ n2 == NULL) return false;
            if(n1) {
                if(n1->val != n2->val)return false;
                q1.push(n1->left);
                q1.push(n1->right);
                q2.push(n2->left);
                q2.push(n2->right);
            }
        }
        // if(q1.size() || q2.size()) return false;
        return true;    
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(root->val == subRoot->val &&  check(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
