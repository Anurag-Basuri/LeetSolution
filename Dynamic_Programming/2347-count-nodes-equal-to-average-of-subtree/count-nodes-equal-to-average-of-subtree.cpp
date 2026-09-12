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
    pair<int, int> recur(TreeNode* root, int &count) {
        if(root == NULL) return {0, 0};

        auto left = recur(root->left, count);
        auto right = recur(root->right, count);

        int n = left.second + right.second + 1;
        int sum = left.first + right.first + root->val;
        int avg = sum/n;

        if(root->val == avg) count++;

        return {sum, n};
    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        recur(root, count);

        return count;
    }
};