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
    TreeNode* buildHelper(vector<int>& inorder, int ins, int inl, vector<int>& postorder, int posts, int postl, unordered_map<int, int>& index) {
        if (posts > postl || ins > inl) {
            return nullptr;
        }

        // Last element of postorder is the root of current subtree
        TreeNode* root = new TreeNode(postorder[postl]);

        // Find the index of the root in inorder traversal
        int ind = index[root->val];

        // Number of elements in the left subtree
        int x = ind - ins;

        // Recursively build left and right subtrees
        root->left = buildHelper(inorder, ins, ind - 1, postorder, posts, posts + x - 1, index);
        root->right = buildHelper(inorder, ind + 1, inl, postorder, posts + x, postl - 1, index);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Map value to index in inorder traversal
        unordered_map<int, int> index;
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }

        // Build the tree
        return buildHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, index);
    }
};
