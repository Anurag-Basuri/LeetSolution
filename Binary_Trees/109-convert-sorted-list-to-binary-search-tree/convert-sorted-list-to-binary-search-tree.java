/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
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
    public TreeNode sortedListToBST(ListNode head) {
        if (head == null) return null;
        if (head.next == null) return new TreeNode(head.val);

        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = null;

        // Finding the middle element
        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        // Create the root node with the middle element
        TreeNode root = new TreeNode(slow.val);

        // Disconnect the left part of the list
        fast = slow.next;
        if (prev != null) {
            prev.next = null;
        }

        // Recursively build left and right subtrees
        root.left = sortedListToBST(head);   // Left subtree
        root.right = sortedListToBST(fast);  // Right subtree

        return root;
    }
}
