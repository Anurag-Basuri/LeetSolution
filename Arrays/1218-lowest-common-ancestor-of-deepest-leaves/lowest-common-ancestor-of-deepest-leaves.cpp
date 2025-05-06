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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> deepest;

        while (!q.empty()) {
            int size = q.size();
            deepest.clear();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                deepest.push_back(node);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        TreeNode* ans = deepest[0];
        for (int i = 1; i < deepest.size(); i++) {
            ans = lca(root, ans, deepest[i]);
        }
        return ans;
    }
};
