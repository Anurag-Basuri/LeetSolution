# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        ans = []
        if root is None:
            return ans
        
        temp = deque([root])

        while temp:
            l = len(temp)
            val = 0

            for _ in range(l):
                node = temp.popleft()
                val = node.val

                if node.left:
                    temp.append(node.left)
                if node.right:
                    temp.append(node.right)

            ans.append(val)

        return ans      