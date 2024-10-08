# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        if root is None:
            return ans

        temp = deque([root])
        ltor = True

        while temp:
            l = len(temp)
            tree = [0] * l

            for i in range(l):
                node = temp.popleft()
                
                if ltor:
                    tree[i] = node.val
                else:
                    tree[l - 1 - i] = node.val

                if node.left:
                    temp.append(node.left)
                if node.right:
                    temp.append(node.right)

            ltor = not ltor
            ans.append(tree)

        return ans
    