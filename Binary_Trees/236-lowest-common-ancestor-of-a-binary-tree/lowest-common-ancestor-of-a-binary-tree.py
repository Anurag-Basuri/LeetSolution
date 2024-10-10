# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def path(self, root: Optional[TreeNode], ans: List[int], x: int) -> bool:
        if root is None:
            return False

        ans.append(root.val)

        if root.val == x:
            return True

        if self.path(root.left, ans, x) or self.path(root.right, ans, x):
            return True

        ans.pop()
        return False

    def lowestCommonAncestor(self, root: Optional[TreeNode], p: TreeNode, q: TreeNode) -> TreeNode:
        pathp, pathq = [], []

        self.path(root, pathp, p.val)
        self.path(root, pathq, q.val)

        i = 0
        while i < len(pathp) and i < len(pathq):
            if pathp[i] != pathq[i]:
                break
            i += 1

        return TreeNode(pathp[i - 1])
      