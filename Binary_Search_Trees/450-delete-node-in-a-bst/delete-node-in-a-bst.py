# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findLeft(self, root: TreeNode) -> TreeNode:
        while root.left is not None:
            root = root.left
        return root

    def helper(self, root: TreeNode) -> TreeNode:
        if root.left is None:
            return root.right
        if root.right is None:
            return root.left

        lastLeft = self.findLeft(root.right)
        lastLeft.left = root.left

        return root.right

    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if root is None:
            return None
        if root.val == key:
            return self.helper(root)

        dummy = root
        while dummy is not None:
            if dummy.val > key:
                if dummy.left and dummy.left.val == key:
                    dummy.left = self.helper(dummy.left)
                    break
                else:
                    dummy = dummy.left
            else:
                if dummy.right and dummy.right.val == key:
                    dummy.right = self.helper(dummy.right)
                    break
                else:
                    dummy = dummy.right

        return root  