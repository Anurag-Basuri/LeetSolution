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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        
        queue<TreeNode*> temp;
        int count = 0;
        temp.push(root);

        while (!temp.empty()) {
            TreeNode* node = temp.front();
            temp.pop();
            count++;

            if (node->left != nullptr) temp.push(node->left);
            if (node->right != nullptr) temp.push(node->right);
        }

        return count;
    }
};
