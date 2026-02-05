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
    private static int dfs(TreeNode root, int largest) {
        if (root == null) return 0;
        int count = 0;
        if (root.val >= largest) {
            count = 1;
            largest = root.val;
        }
        count += dfs(root.left, largest);
        count += dfs(root.right, largest);
        return count;
    }

    public static int goodNodes(TreeNode root) {
        return dfs(root, root.val);
    }
}