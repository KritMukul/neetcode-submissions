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
    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     if(p == NULL ^ q == NULL) return false;
    //     if(!p && !q) return true;
    //     if(p->val != q->val) return false;
    //     return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    // }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1, q2;

        q1.push(p);
        q2.push(q);

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
        if(q1.size() || q2.size()) return false;
        return true;
    }
};
