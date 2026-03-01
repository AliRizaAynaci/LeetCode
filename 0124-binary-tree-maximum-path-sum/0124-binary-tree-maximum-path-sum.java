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
    private int maxPathSum = Integer.MIN_VALUE;

    private int dfs(TreeNode root) {
        if (root == null) return 0;
        int left = Math.max(dfs(root.left), 0);
        int right = Math.max(dfs(root.right), 0);
        maxPathSum = Math.max(maxPathSum, left + right + root.val);
        return Math.max(left, right) + root.val;
        /**
        8
            20
        15      5
         */
    }

    public int maxPathSum(TreeNode root) {
        dfs(root);
        return maxPathSum;
    }
}