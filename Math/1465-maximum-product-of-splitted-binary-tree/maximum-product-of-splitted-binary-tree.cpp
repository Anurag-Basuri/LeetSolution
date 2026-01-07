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
private:
    long long tree_sum(TreeNode* root) {
        if (!root) return 0;
        return root->val + tree_sum(root->left) + tree_sum(root->right);
    }

    long long max_prod(TreeNode* root) {
        if (!root) return 0;

        long long left = max_prod(root->left);
        long long right = max_prod(root->right);

        long long currSum = root->val + left + right;

        maxProd = max(maxProd, currSum * (totalSum - currSum));

        return currSum;
    }

public:
    long long totalSum = 0;
    long long maxProd = 0;

    int maxProduct(TreeNode* root) {
        totalSum = tree_sum(root);
        max_prod(root);

        int MOD = 1e9 + 7;
        return maxProd % MOD;
    }
};
