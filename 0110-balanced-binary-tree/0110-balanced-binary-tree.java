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
    public static int depth(TreeNode root) {
        if (root == null) return 0;
        int left = depth(root.left);
        int right = depth(root.right);
        return 1 + Math.max(left, right);
    }

    public static boolean isBalanced(TreeNode root) {
        if (root == null) return true;
        int diff = Math.abs(depth(root.left) - depth(root.right));
        if (diff > 1) return false;
        return isBalanced(root.left) && isBalanced(root.right);
    }
}