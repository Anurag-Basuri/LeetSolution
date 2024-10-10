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
    public boolean path(TreeNode root, List<Integer> ans, int x) {
        if (root == null) return false;

        ans.add(root.val);

        if (root.val == x) return true;

        if (path(root.left, ans, x) || path(root.right, ans, x)) return true;

        ans.remove(ans.size() - 1);
        return false;
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        List<Integer> pathp = new ArrayList<>();
        List<Integer> pathq = new ArrayList<>();

        path(root, pathp, p.val);
        path(root, pathq, q.val);

        int i;
        for (i = 0; i < pathp.size() && i < pathq.size(); i++) {
            if (!pathp.get(i).equals(pathq.get(i))) break;
        }

        return new TreeNode(pathp.get(i - 1));
    }
}
