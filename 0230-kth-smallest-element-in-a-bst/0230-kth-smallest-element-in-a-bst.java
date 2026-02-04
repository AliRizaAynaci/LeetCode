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
    private static void inorder(TreeNode root, int k, int[] count, int[] res) {
        if (root == null) return;
        inorder(root.left, k, count, res);
        if (res[0] != -1) {
            return;
        }
        count[0]++;
        if (count[0] == k) {
            res[0] = root.val;
            return;
        }
        inorder(root.right, k, count, res);
    }

    public static int kthSmallest(TreeNode root, int k) {
        int[] count = new int[1];
        int[] res = {-1};
        inorder(root, k, count, res);
        return res[0];
    }
}