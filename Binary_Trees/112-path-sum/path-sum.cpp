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
    bool dfs(TreeNode* root, int target, int cursum){
        if(root == NULL) return false;

        cursum += root->val;
        if(root->left == NULL && root->right == NULL) return cursum == target;

        return dfs(root->left, target, cursum) || dfs(root->right, target, cursum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;

        return dfs(root, targetSum, 0);
    }
};