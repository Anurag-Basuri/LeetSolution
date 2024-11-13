# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder(self, root, k, counter, klargest):
        if(root is None or counter[0] >= k):
            return
        
        self.inorder(root.left, k, counter, klargest)
        
        counter[0] += 1
        if(counter[0] == k):
            klargest[0] = root.val
            return
        
        self.inorder(root.right, k, counter, klargest)

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        klargest = [-1]
        counter = [0]

        self.inorder(root, k, counter, klargest)

        return klargest[0]