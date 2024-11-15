class Solution {
public:
    TreeNode* buildHelper(vector<int>& preorder, int ps, int pl, vector<int>& inorder, int is_, int il, unordered_map<int, int>& indexMap) {
        if (ps > pl || is_ > il) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[ps]);
        int in_idx = indexMap[root->val];
        int leftsize = in_idx - is_;

        root->left = buildHelper(preorder, ps + 1, ps + leftsize, inorder, is_, in_idx - 1, indexMap);
        root->right = buildHelper(preorder, ps + leftsize + 1, pl, inorder, in_idx + 1, il, indexMap);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        
        unordered_map<int, int> indexMap;
        for (int i = 0; i < inorder.size(); i++) {
            indexMap[inorder[i]] = i;
        }

        return buildHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, indexMap);
    }
};