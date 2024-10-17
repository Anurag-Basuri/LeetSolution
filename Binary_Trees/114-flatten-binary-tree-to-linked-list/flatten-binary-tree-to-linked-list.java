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
    public TreeNode linkedlist(TreeNode root) {
        if (root == null) {
            return null;
        }

        TreeNode left = linkedlist(root.left);
        TreeNode right = linkedlist(root.right);

        if (left != null) {
            TreeNode trav = left;

            while (trav.right != null) {
                trav = trav.right;
            }
            trav.right = right;

            root.right = left;
            root.left = null;
        }

        return root;
    }

    public void flatten(TreeNode root) {
        linkedlist(root);
    }
}
