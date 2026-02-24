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
    int sumRootToLeaf(TreeNode* root,int x){
        if(!root) return 0;

        int val = x*2 + root->val;

        if(root->left==NULL && root->right == NULL) return val;
        
        return sumRootToLeaf(root->left,val) + sumRootToLeaf(root->right,val);
    }

    int sumRootToLeaf(TreeNode* root) {
        return sumRootToLeaf(root,0);
    }
};