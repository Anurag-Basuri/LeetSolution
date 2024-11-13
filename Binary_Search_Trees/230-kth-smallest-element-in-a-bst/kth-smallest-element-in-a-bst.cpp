class Solution {
public:
    void inorder(TreeNode* root, int& counter, int& k, int& klargest){
        if(root == NULL || counter >= k) return;

        inorder(root->left, counter, k, klargest);
        
        counter++;
        if(counter == k){
            klargest = root->val;
            return;
        }

        inorder(root->right, counter, k, klargest);
    }

    int kthSmallest(TreeNode* root, int k) {
        int klargest, counter = 0;

        inorder(root, counter, k, klargest);
        return klargest;
    }
};