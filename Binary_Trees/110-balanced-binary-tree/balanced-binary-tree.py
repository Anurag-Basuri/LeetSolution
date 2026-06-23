# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def find(self, root):
        if root is None:
            return 0
        lh = self.find(root.left)
        if lh == -1:
            return -1
        rh = self.find(root.right)
        if rh == -1:
            return -1

        if abs(lh - rh) > 1:
            return -1

        return 1 + max(lh, rh)

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.find(root) != -1