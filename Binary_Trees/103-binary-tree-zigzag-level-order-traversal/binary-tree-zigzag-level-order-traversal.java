/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) return ans;

        Queue<TreeNode> temp = new LinkedList<>();
        temp.offer(root);
        boolean ltor = true;

        while (!temp.isEmpty()) {
            int l = temp.size();
            List<Integer> tree = new ArrayList<>(Collections.nCopies(l, 0));

            for (int i = 0; i < l; i++) {
                TreeNode node = temp.poll();
                tree.set(ltor ? i : l - 1 - i, node.val);  

                if (node.left != null) temp.offer(node.left);
                if (node.right != null) temp.offer(node.right);
            }

            ltor = !ltor;
            ans.add(tree);
        }

        return ans;
    }
}
