# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def path(self, root: Optional[TreeNode], current_path: str, paths: List[str]):
        if root is None:
            return
        
        current_path += str(root.val)
        
        if root.left is None and root.right is None:
            paths.append(current_path)
        else:
            current_path += "->"
            self.path(root.left, current_path, paths)
            self.path(root.right, current_path, paths)

    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        paths = []
        if root:
            self.path(root, "", paths)
        return paths