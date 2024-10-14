    # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Definition for a binary tree node.
class Solution:
    def buildHelper(self, preorder, ps, pl, inorder, is_, il, index):
        # Base case: if the start index is greater than the end index, return None
        if ps > pl or is_ > il:
            return None
        
        # Root node is the first element in the preorder traversal
        root_val = preorder[ps]
        root = TreeNode(root_val)
        
        # Find the index of the root value in the inorder traversal using the index map
        inorder_index = index[root_val]
        
        # Calculate the number of elements in the left subtree
        left_subtree_size = inorder_index - is_

        # Recursively build the left subtree
        root.left = self.buildHelper(preorder, ps + 1, ps + left_subtree_size, inorder, is_, inorder_index - 1, index)
        
        # Recursively build the right subtree
        root.right = self.buildHelper(preorder, ps + left_subtree_size + 1, pl, inorder, inorder_index + 1, il, index)
        
        return root

    def buildTree(self, preorder: list[int], inorder: list[int]) -> TreeNode:
        # Create a map to store the index of each value in the inorder traversal
        index = {val: idx for idx, val in enumerate(inorder)}
        
        # Call the helper function to build the tree
        return self.buildHelper(preorder, 0, len(preorder) - 1, inorder, 0, len(inorder) - 1, index)
