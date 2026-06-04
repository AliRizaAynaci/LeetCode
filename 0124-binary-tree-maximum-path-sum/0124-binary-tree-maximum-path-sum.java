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
    private int dfs(TreeNode root, int[] maxSum) {
        if (root == null) return 0;
        int l = Math.max(dfs(root.left, maxSum), 0);
        int r = Math.max(dfs(root.right, maxSum), 0);
        maxSum[0] = Math.max(maxSum[0], l + r + root.val);
        return Math.max(l, r) + root.val;
    }

    public int maxPathSum(TreeNode root) {
        int[] maxSum = {Integer.MIN_VALUE};
        dfs(root, maxSum);
        return maxSum[0];
    }
}