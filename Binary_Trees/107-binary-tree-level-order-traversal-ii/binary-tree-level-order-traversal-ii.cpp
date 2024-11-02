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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
         
        if(root == NULL) return result;

        queue<TreeNode*> temp;
        temp.push(root);

        while(!temp.empty()){
            int size = temp.size();
            vector<int> nodes;

            for(int i = 0; i < size; i++){
                TreeNode* nod = temp.front();
                temp.pop();

                if(nod->left != NULL) temp.push(nod->left);
                if(nod->right != NULL) temp.push(nod->right);

                nodes.push_back(nod->val);
            }

            result.insert(result.begin(), nodes);
        }

        return result;
    }
};
