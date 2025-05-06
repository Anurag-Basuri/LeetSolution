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
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || root == q || root == p) return root;

        auto left = LCA(root->left, p, q);
        auto right = LCA(root->right, p, q);

        if(left && right) return root;
        return  left ? left:right;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root == NULL) return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> last;

        while(!q.empty()){
            int n = q.size();
            last.clear();

            for(int i = 0; i < n; i++){
                auto node = q.front();
                q.pop();
                last.push_back(node);

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
        }

        auto ans = last[0];
        for(int i = 1; i < last.size(); i++)
            ans = LCA(root, ans, last[i]);
        
        return ans;
    }
};