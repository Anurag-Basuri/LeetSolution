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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }

        queue<TreeNode*> temp;
        temp.push(root);
        bool ltor = true;

        while(!temp.empty()){
            int l = temp.size();
            vector<int> tree(l);

            for(int i = 0; i < l; i++){
                TreeNode* node = temp.front();
                temp.pop();
                tree[ltor? i : l-1-i] = node->val;

                if(node->left != NULL) temp.push(node->left);
                if(node->right != NULL) temp.push(node->right);
            }
            
            ltor = !ltor;
            ans.push_back(tree);
        }

        return ans;
    }
};