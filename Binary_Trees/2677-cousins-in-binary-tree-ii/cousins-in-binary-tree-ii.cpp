/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == NULL)
            return root;

        queue<TreeNode*> temp;
        temp.push(root);

        root->val = 0;

        while (!temp.empty()) {
            int lsize = temp.size();
            int totalSum = 0;

            unordered_map<TreeNode*, int> cousins;
            for (int i = 0; i < lsize; i++) {
                TreeNode* node = temp.front();
                temp.pop();
                int childsum = 0;

                if (node->left != NULL) {
                    temp.push(node->left);
                    childsum += node->left->val;
                }

                if (node->right != NULL) {
                    temp.push(node->right);
                    childsum += node->right->val;
                }

                cousins[node] = childsum;
                totalSum += childsum;
            }

            for (auto& x : cousins) {
                TreeNode* node = x.first;
                int childsum = x.second;

                if (node->left != NULL)
                    node->left->val = totalSum - childsum;

                if (node->right != NULL)
                    node->right->val = totalSum - childsum;
            }
        }

        return root;
    }
};