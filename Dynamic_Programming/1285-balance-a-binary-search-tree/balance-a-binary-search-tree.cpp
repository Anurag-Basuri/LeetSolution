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
    void inorder(TreeNode* root, vector<int> &travs) {
        if (root == nullptr) return;

        inorder(root->left, travs);
        travs.push_back(root->val);
        inorder(root->right, travs);
    }

    TreeNode* buildBalancedBST(int l, int r, vector<int> travs) {
        if (l > r) return nullptr;

        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(travs[mid]);

        root->left = buildBalancedBST(l, mid - 1, travs);
        root->right = buildBalancedBST(mid + 1, r, travs);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> travs;
        inorder(root, travs);

        return buildBalancedBST(0, travs.size() - 1, travs);
    }
};
