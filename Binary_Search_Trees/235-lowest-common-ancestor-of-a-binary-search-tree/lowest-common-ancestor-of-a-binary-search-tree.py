# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root is None:
            return None

        cur = root.val

        if cur > p.val and cur > q.val:
            return self.lowestCommonAncestor(root.left, p, q)

        if cur < p.val and cur < q.val:
            return self.lowestCommonAncestor(root.right, p, q)

        return root
