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
    private int findMaxPath(TreeNode root, int[] maxSum) {
        if (root == null) return 0;
        int l = Math.max(findMaxPath(root.left, maxSum), 0);
        int r = Math.max(findMaxPath(root.right, maxSum), 0);
        int currSum = l + r + root.val;
        maxSum[0] = Math.max(maxSum[0], currSum);
        return Math.max(l, r) + root.val;
    }

    public int maxPathSum(TreeNode root) {
        if (root == null) return 0;
        int[] maxSum = new int[] {Integer.MIN_VALUE};
        findMaxPath(root, maxSum);
        return maxSum[0];
    }
}