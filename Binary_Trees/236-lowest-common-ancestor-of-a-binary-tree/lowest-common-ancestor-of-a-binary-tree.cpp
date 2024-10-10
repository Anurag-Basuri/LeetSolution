/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool path(TreeNode* root, vector<int>& ans, int x) {
        if (root == NULL) return false;

        ans.push_back(root->val);

        if (root->val == x) return true;

        if (path(root->left, ans, x) || path(root->right, ans, x)) return true;

        ans.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> pathp, pathq;

        path(root, pathp, p->val);
        path(root, pathq, q->val);

        int i;
        for (i = 0; i < pathp.size() && i < pathq.size(); i++) {
            if (pathp[i] != pathq[i]) break;
        }

        return new TreeNode(pathp[i - 1]);
    }
};
