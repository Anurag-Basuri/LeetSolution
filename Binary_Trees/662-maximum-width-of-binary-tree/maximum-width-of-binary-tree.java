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
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    // Custom class to store a node, its position, and its level
    class NodeInfo {
        TreeNode node;
        long num;
        int lev;

        NodeInfo(TreeNode node, long num, int lev) {
            this.node = node;
            this.num = num;
            this.lev = lev;
        }
    }

    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;

        Queue<NodeInfo> temp = new LinkedList<>();
        temp.offer(new NodeInfo(root, 1, 0));

        int res = 0;
        int prelev = 0;
        long prenum = 1;

        while (!temp.isEmpty()) {
            NodeInfo current = temp.poll();
            TreeNode node = current.node;
            long num = current.num;
            int lev = current.lev;

            if (lev > prelev) {
                prelev = lev;
                prenum = num;
            }

            res = Math.max(res, (int)(num - prenum + 1));

            if (node.left != null) {
                temp.offer(new NodeInfo(node.left, 2 * num, lev + 1));
            }
            if (node.right != null) {
                temp.offer(new NodeInfo(node.right, 2 * num + 1, lev + 1));
            }
        }

        return res;
    }
}
