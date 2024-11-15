# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildHelper(self, preorder, ps, pl, inorder, is_, il, indexMap):
        if ps > pl and is_ > il:
            return None

        root = TreeNode(preorder[ps])

        in_idx = indexMap[root.val]
        leftsize = in_idx - is_

        root.left = self.buildHelper(preorder, ps + 1, ps + leftsize, inorder, is_, in_idx - 1, indexMap)
        root.right = self.buildHelper(preorder, ps + leftsize + 1, pl, inorder, in_idx + 1, il, indexMap)

        return root

    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        inorder = sorted(preorder)
        indexMap = {val: idx for idx, val in enumerate(inorder)}

        return self.buildHelper(preorder, 0, len(preorder) - 1, inorder, 0, len(inorder) - 1, indexMap)