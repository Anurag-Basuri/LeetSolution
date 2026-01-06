# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Dummy node to handle edge cases like head being a duplicate
        dummy = ListNode(0)
        dummy.next = head
        
        prev = dummy  # Previous node
        curr = head   # Current node
        
        while curr:
            # Move the current node until the end of duplicates
            while curr.next and curr.val == curr.next.val:
                curr = curr.next
            
            # If prev.next is still curr, there was no duplicate for this value
            if prev.next == curr:
                prev = prev.next
            else:
                # Skip all duplicates
                prev.next = curr.next
            
            # Move to the next node
            curr = curr.next
        
        return dummy.next