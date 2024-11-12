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
    TreeNode* findLeft(TreeNode* root){
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    TreeNode* helper(TreeNode* root){
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;

        TreeNode* lastLeft = findLeft(root->right);
        lastLeft->left = root->left;

        return root->right;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key) return helper(root);

        TreeNode* dummy = root;
        while(dummy != NULL){
            if(dummy->val > key){
                if(dummy->left && dummy->left->val == key){
                    dummy->left = helper(dummy->left);
                    break;
                }
                else dummy = dummy->left;
            }
            else{
                if(dummy->right && dummy->right->val == key){
                    dummy->right = helper(dummy->right);
                    break;
                }
                else dummy = dummy->right;
            }
        }

        return root;
    }
};
