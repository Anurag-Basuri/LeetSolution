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
    pair<TreeNode*, int> findSubtree(TreeNode* root) {
        if(!root) return {nullptr, 0};

        auto left = findSubtree(root->left);
        auto right = findSubtree(root->right);

        if(left.second == right.second) return {root, left.second+1};
        else if(right.second > left.second) return {right.first, right.second + 1};
        else return {left.first, left.second + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        auto ans = findSubtree(root);

        return ans.first;
    }
};