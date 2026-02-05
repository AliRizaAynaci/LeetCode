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
    private static int dfs(TreeNode root, int largest, int[] count) {
        if (root == null) return 0;
        if (root.val >= largest) {
            count[0] = 1;
            largest = root.val;
        } else count[0] = 0;
        count[0] += dfs(root.left, largest, count);
        count[0] += dfs(root.right, largest, count);
        return count[0];
    }

    public static int goodNodes(TreeNode root) {
        int[] count = new int[1];
        return dfs(root, root.val, count);
    }
}