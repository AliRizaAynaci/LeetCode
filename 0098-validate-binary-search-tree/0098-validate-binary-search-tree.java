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
    private static boolean isValid(TreeNode node, long minBoundary, long maxBoundary) {
        if (node == null) return true;
        if (node.val <= minBoundary || node.val >= maxBoundary) return false;
        return isValid(node.left, minBoundary, node.val) && isValid(node.right, node.val, maxBoundary);
    }

    public static boolean isValidBST(TreeNode root) {
        return isValid(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}