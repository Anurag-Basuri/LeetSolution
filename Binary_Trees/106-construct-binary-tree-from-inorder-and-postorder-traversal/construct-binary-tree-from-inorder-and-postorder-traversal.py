# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildHelper(self, inorder, ins, inl, postorder, posts, postl, index):
        if posts > postl or ins > inl:
            return None
        
        # The last element of postorder is the root of the current subtree
        root = TreeNode(postorder[postl])

        # Find the index of the root in inorder traversal
        ind = index[root.val]
        
        # Number of nodes in the left subtree
        x = ind - ins

        # Recursively build the left and right subtrees
        root.left = self.buildHelper(inorder, ins, ind - 1, postorder, posts, posts + x - 1, index)
        root.right = self.buildHelper(inorder, ind + 1, inl, postorder, posts + x, postl - 1, index)

        return root

    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        # Map the values to their indices in inorder traversal
        index = {val: i for i, val in enumerate(inorder)}
        
        # Build the tree using the helper function
        return self.buildHelper(inorder, 0, len(inorder) - 1, postorder, 0, len(postorder) - 1, index)
