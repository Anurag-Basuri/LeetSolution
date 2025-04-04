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
    pair<TreeNode*, int> findLCA(TreeNode* root) {
        if(root == NULL) return {nullptr, 0};

        auto left = findLCA(root->left);
        auto right = findLCA(root->right);

        if(left.second == right.second) return {root, left.second + 1};
        else if(left.second > right.second) return {left.first, left.second + 1};
        else return {right.first, right.second + 1};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto ans = findLCA(root);

        return ans.first;
    }
};