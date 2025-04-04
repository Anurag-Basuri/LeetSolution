# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def findLCA(node):
            if not node:
                return (None, 0)
            
            left_node, left_depth = findLCA(node.left)
            right_node, right_depth = findLCA(node.right)

            if left_depth == right_depth:
                return (node, left_depth + 1)
            elif left_depth > right_depth:
                return (left_node, left_depth + 1)
            else:
                return (right_node, right_depth + 1)
        
        return findLCA(root)[0]
     