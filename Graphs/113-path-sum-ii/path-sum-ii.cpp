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
    void dfs(TreeNode* root, int cursum, vector<int>& temp, vector<vector<int>>& ans) {
        if (root == NULL) return;

        temp.push_back(root->val);
        if (root->left == NULL && root->right == NULL && cursum == root->val) {
            ans.push_back(temp);
        }

        dfs(root->left, cursum - root->val, temp, ans);
        dfs(root->right, cursum - root->val, temp, ans);

        // Backtrack to explore other paths
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(root, targetSum, temp, ans);
        return ans;
    }
};
