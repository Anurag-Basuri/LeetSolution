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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        queue<pair<TreeNode*, long long>> temp;  // queue stores {node, index}
        temp.push({root, 0});  // Start with index 0 for root
        
        int res = 0;
        
        while (!temp.empty()) {
            int size = temp.size();
            long long minIndex = temp.front().second;  // Get the minimum index at this level
            long long left, right;
            
            for (int i = 0; i < size; i++) {
                auto [node, index] = temp.front();
                temp.pop();
                
                // Normalize the index to avoid overflow
                index -= minIndex;
                
                if (i == 0) left = index;  // Leftmost node in the level
                if (i == size - 1) right = index;  // Rightmost node in the level
                
                if (node->left) {
                    temp.push({node->left, 2 * index});
                }
                if (node->right) {
                    temp.push({node->right, 2 * index + 1});
                }
            }
            
            res = max(res, int(right - left + 1));
        }
        
        return res;
    }
};
