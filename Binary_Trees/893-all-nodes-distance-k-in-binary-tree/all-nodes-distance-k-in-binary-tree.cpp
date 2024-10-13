/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void match_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> temp;
        temp.push(root);

        while (!temp.empty()) {
            TreeNode* node = temp.front();
            temp.pop();

            if (node->left) {
                parent[node->left] = node;
                temp.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                temp.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        match_parent(root, parent);

        queue<TreeNode*> temp;
        temp.push(target);
        unordered_map<TreeNode*, bool> seen;
        seen[target] = true;

        int cur = 0;

        while (!temp.empty()) {
            if (cur == k) break;
            cur++;

            int size = temp.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = temp.front();
                temp.pop();

                // Check the left child
                if (node->left && !seen[node->left]) {
                    seen[node->left] = true;
                    temp.push(node->left);
                }

                // Check the right child
                if (node->right && !seen[node->right]) {
                    seen[node->right] = true;
                    temp.push(node->right);
                }

                // Check the parent
                if (parent[node] && !seen[parent[node]]) {
                    seen[parent[node]] = true;
                    temp.push(parent[node]);
                }
            }
        }

        vector<int> ans;
        while (!temp.empty()) {
            ans.push_back(temp.front()->val);
            temp.pop();
        }

        return ans;
    }
};
