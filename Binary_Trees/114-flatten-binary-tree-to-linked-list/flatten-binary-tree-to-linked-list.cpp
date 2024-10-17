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
    TreeNode* linkedlist(TreeNode* root){
        if(root == NULL) return NULL;

        TreeNode* left = linkedlist(root->left);
        TreeNode* right = linkedlist(root->right);

        if (left) {
            TreeNode* trav = left;

            while (trav->right != NULL) {
                trav = trav->right;
            }
            trav->right = right;
            
            root->right = left;
            root->left = NULL;
        }

        return root;
    }

    void flatten(TreeNode* root) {
        linkedlist(root);
    }
};