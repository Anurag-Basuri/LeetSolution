# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def linkedlist(self, root: TreeNode) -> TreeNode:
        if root is None:
            return None

        left = self.linkedlist(root.left)
        right = self.linkedlist(root.right)

        if left is not None:
            trav = left
            while trav.right is not None:
                trav = trav.right
            trav.right = right

            root.right = left
            root.left = None

        return root

    def flatten(self, root: TreeNode) -> None:
        self.linkedlist(root)
       