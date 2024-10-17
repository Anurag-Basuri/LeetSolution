# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    # Encodes a tree to a single string.
    def serialize(self, root):
        if not root:
            return ""

        queue = collections.deque([root])
        result = []

        while queue:
            node = queue.popleft()

            if node:
                result.append(str(node.val))
                queue.append(node.left)
                queue.append(node.right)
            else:
                result.append("#")

        return ",".join(result)

    # Decodes your encoded data to tree.
    def deserialize(self, data):
        if not data:
            return None

        values = data.split(",")
        root = TreeNode(int(values[0]))
        queue = collections.deque([root])
        i = 1

        while queue:
            node = queue.popleft()

            if values[i] != "#":
                leftNode = TreeNode(int(values[i]))
                node.left = leftNode
                queue.append(leftNode)
            i += 1

            if values[i] != "#":
                rightNode = TreeNode(int(values[i]))
                node.right = rightNode
                queue.append(rightNode)
            i += 1

        return root
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))