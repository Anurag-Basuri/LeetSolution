/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    // Method to map each node to its parent
    public void matchParent(TreeNode root, Map<TreeNode, TreeNode> parentMap) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();

            if (node.left != null) {
                parentMap.put(node.left, node);
                queue.add(node.left);
            }

            if (node.right != null) {
                parentMap.put(node.right, node);
                queue.add(node.right);
            }
        }
    }

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        Map<TreeNode, TreeNode> parentMap = new HashMap<>();
        matchParent(root, parentMap);

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(target);
        Set<TreeNode> seen = new HashSet<>();
        seen.add(target);

        int curDistance = 0;

        while (!queue.isEmpty()) {
            if (curDistance == k) break;
            curDistance++;

            int size = queue.size();

            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();

                // Check left child
                if (node.left != null && !seen.contains(node.left)) {
                    seen.add(node.left);
                    queue.add(node.left);
                }

                // Check right child
                if (node.right != null && !seen.contains(node.right)) {
                    seen.add(node.right);
                    queue.add(node.right);
                }

                // Check parent
                if (parentMap.containsKey(node) && !seen.contains(parentMap.get(node))) {
                    seen.add(parentMap.get(node));
                    queue.add(parentMap.get(node));
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        while (!queue.isEmpty()) {
            result.add(queue.poll().val);
        }

        return result;
    }
}
