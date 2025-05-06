# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lca(self, root, p, q):
        if not root or root == p or root == q:
            return root
        left = self.lca(root.left, p, q)
        right = self.lca(root.right, p, q)
        if left and right:
            return root
        return left if left else right

    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None

        from collections import deque
        queue = deque([root])
        deepest = []

        while queue:
            size = len(queue)
            deepest = []
            for _ in range(size):
                node = queue.popleft()
                deepest.append(node)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

        ans = deepest[0]
        for i in range(1, len(deepest)):
            ans = self.lca(root, ans, deepest[i])

        return ans
