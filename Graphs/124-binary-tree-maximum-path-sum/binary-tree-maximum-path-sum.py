# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxsum(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        
        # Calculate the maximum path sum for left and right subtrees
        ls = max(0, self.maxsum(root.left))
        rs = max(0, self.maxsum(root.right))

        # Update the maximum path sum including the current node
        self.max = max(self.max, ls + rs + root.val)
        
        # Return the maximum path sum ending at the current node
        return root.val + max(ls, rs)

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.max = float('-inf')
        self.maxsum(root)
        return self.max