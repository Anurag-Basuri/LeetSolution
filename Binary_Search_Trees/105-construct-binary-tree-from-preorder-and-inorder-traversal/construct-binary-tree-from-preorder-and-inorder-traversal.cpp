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
    TreeNode* buildHelper(vector<int>& preorder, int ps, int pl, vector<int>& inorder, int is_, int il, unordered_map<int, int>& indexMap) {
        // Base case: if the start index is greater than the end index, return NULL
        if (ps > pl ) {
            return nullptr;
        }
        
        // Root node is the first element in the current range of the preorder traversal
        int rootVal = preorder[ps];
        TreeNode* root = new TreeNode(rootVal);
        
        // Find the index of the root value in the inorder traversal using the index map
        int inorderIndex = indexMap[rootVal];
        
        // Calculate the size of the left subtree
        int leftSubtreeSize = inorderIndex - is_;
        
        // Recursively build the left subtree
        root->left = buildHelper(preorder, ps + 1, ps + leftSubtreeSize, inorder, is_, inorderIndex - 1, indexMap);
        
        // Recursively build the right subtree
        root->right = buildHelper(preorder, ps + leftSubtreeSize + 1, pl, inorder, inorderIndex + 1, il, indexMap);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create a map to store the index of each value in the inorder traversal
        unordered_map<int, int> indexMap;
        for (int i = 0; i < inorder.size(); i++) {
            indexMap[inorder[i]] = i;
        }

        // Call the helper function to build the tree
        return buildHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, indexMap);
    }
};