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
    int maxLevelSum(TreeNode* root) {
        if (root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int max_val = root->val;
        int level = 1;
        int lev = 1;

        while(!q.empty()) {
            int l = q.size();
            int sum = 0;

            for(int i = 0; i < l; i++) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node->left) q.push(node->left);

                if(node->right) q.push(node->right);
            }

            if (sum > max_val) {
                level = lev;
                max_val = sum;
            }

            lev++;
        }

        return level;
    }
};