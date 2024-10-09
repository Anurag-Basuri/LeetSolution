# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        # Dictionary: x-coordinate -> list of (y-coordinate, node value)
        nodes = defaultdict(list)
        
        # Queue for BFS: stores (node, x, y)
        temp = deque([(root, 0, 0)])
        
        while temp:
            node, x, y = temp.popleft()
            
            # Store the node value in the nodes dictionary
            nodes[x].append((y, node.val))
            
            # Add left and right children with updated coordinates
            if node.left:
                temp.append((node.left, x - 1, y + 1))
            if node.right:
                temp.append((node.right, x + 1, y + 1))
        
        # Prepare the result
        result = []
        
        # Sort by x-coordinate, and then for each x, sort by y-coordinate and node value
        for x in sorted(nodes.keys()):
            # Sort by y-coordinate first, and if y is the same, sort by node value
            column = sorted(nodes[x], key=lambda p: (p[0], p[1]))
            # Extract node values for this column
            result.append([val for y, val in column])
        
        return result
        