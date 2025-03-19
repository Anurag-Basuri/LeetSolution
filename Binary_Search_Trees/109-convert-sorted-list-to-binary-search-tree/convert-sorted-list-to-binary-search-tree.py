# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        if not head:
            return None
        if not head.next:
            return TreeNode(head.val)

        slow = head
        fast = head
        prev = None

        # Finding the middle element
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next

        # Create the root node with the middle element
        root = TreeNode(slow.val)

        # Disconnect the left part of the list
        if prev:
            prev.next = None

        # Recursively build left and right subtrees
        root.left = self.sortedListToBST(head)    # Left subtree
        root.right = self.sortedListToBST(slow.next)  # Right subtree

        return root
