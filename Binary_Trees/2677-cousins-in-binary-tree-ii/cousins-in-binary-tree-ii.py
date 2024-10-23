# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def replaceValueInTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return root

        temp = deque([root])
        root.val = 0

        while temp:
            lsize = len(temp)
            total_sum = 0

            cousins = {}
            for _ in range(lsize):
                node = temp.popleft()
                child_sum = 0

                if node.left is not None:
                    temp.append(node.left)
                    child_sum += node.left.val

                if node.right is not None:
                    temp.append(node.right)
                    child_sum += node.right.val

                cousins[node] = child_sum
                total_sum += child_sum

            for node, child_sum in cousins.items():
                if node.left is not None:
                    node.left.val = total_sum - child_sum

                if node.right is not None:
                    node.right.val = total_sum - child_sum

        return root
