"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if root is None:
            return None
        
        temp = deque()

        temp.append(root)

        while len(temp) > 0:
            lv_node = []
            size = len(temp)

            for i in range(0, size):
                x = temp.popleft()
                lv_node.append(x)

                if x.left:
                    temp.append(x.left)

                if x.right:
                    temp.append(x.right)
            
            for i in range(1, size):
                lv_node[i-1].next = lv_node[i]
            
            lv_node[-1].next = None
        
        return root