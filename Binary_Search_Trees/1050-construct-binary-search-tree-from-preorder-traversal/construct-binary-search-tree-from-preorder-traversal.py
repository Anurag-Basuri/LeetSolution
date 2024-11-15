class Solution:
    def helper(self, preorder: List[int], ind: int, limit: int) -> Optional[TreeNode]:
        if ind[0] == len(preorder) or preorder[ind[0]] > limit:
            return None

        root = TreeNode(preorder[ind[0]])
        ind[0] += 1

        root.left = self.helper(preorder, ind, root.val)
        root.right = self.helper(preorder, ind, limit)

        return root

    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        ind = [0]
        return self.helper(preorder, ind, float('inf'))