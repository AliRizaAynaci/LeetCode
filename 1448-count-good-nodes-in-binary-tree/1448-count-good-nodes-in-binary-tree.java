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
    private int count = 0;
    private int dfs(TreeNode root, int largest) {
        if (root == null) return 0;
        if (root.val >= largest) {
            count++;
            largest = root.val;
        }
        dfs(root.left, largest);
        dfs(root.right, largest);
        return count;
    }

    public int goodNodes(TreeNode root) {
        if (root == null) return 0;
        return dfs(root, root.val);
    }
}