# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        temp = deque()
        temp.append([root, 1, 0])

        res = 0
        prelev, prenum = 0, 1

        while len(temp) != 0:
            node, num, lev = temp.popleft()

            if lev > prelev:
                prelev = lev
                prenum = num
            
            res = max(res, num - prenum + 1)

            if node.left:
                temp.append([node.left, 2 * num, lev + 1])

            if node.right:
                temp.append([node.right, 2 * num + 1, lev + 1])
        
        return res