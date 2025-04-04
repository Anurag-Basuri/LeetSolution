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
    // Helper class to return both node and depth
    class Pair {
        TreeNode node;
        int depth;
        Pair(TreeNode node, int depth) {
            this.node = node;
            this.depth = depth;
        }
    }

    public TreeNode lcaDeepestLeaves(TreeNode root) {
        return findLCA(root).node;
    }

    private Pair findLCA(TreeNode root) {
        if (root == null) return new Pair(null, 0);

        Pair left = findLCA(root.left);
        Pair right = findLCA(root.right);

        if (left.depth == right.depth) {
            return new Pair(root, left.depth + 1);
        } else if (left.depth > right.depth) {
            return new Pair(left.node, left.depth + 1);
        } else {
            return new Pair(right.node, right.depth + 1);
        }
    }
}
