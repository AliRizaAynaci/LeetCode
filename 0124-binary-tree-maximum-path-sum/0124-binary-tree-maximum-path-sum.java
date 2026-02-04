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
    private static int helper(TreeNode root, int[] maxPathSum) {
        if (root == null) return 0;
        int left = Math.max(helper(root.left, maxPathSum), 0);
        int right = Math.max(helper(root.right, maxPathSum), 0);
        maxPathSum[0] = Math.max(maxPathSum[0], left + right + root.val);
        return Math.max(left, right) + root.val;
    }

    public static int maxPathSum(TreeNode root) {
        int[] maxPathSum = {Integer.MIN_VALUE};
        helper(root, maxPathSum);
        return maxPathSum[0];
    }
}