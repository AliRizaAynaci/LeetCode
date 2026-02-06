/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    // Encodes a tree to a single string.
    public static String serialize(TreeNode root) {
        if (root == null) return "";
        StringBuilder s = new StringBuilder();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (node == null) {
                s.append("N,");
            } else {
                s.append(node.val).append(",");
                q.offer(node.left);
                q.offer(node.right);
            }
        }
        return s.toString();
    }

    // Decodes your encoded data to tree.
    public static TreeNode deserialize(String data) {
        if (data == null || data.isEmpty()) return null;
        String[] dataArray = data.split(",");
        Queue<TreeNode> q = new LinkedList<>();
        TreeNode root = new TreeNode(Integer.parseInt(dataArray[0]));
        q.offer(root);
        int i = 1;
        while (!q.isEmpty() && i < dataArray.length) {
            TreeNode node = q.poll();
            if (!dataArray[i].equals("N")) {
                int val = Integer.parseInt(dataArray[i]);
                node.left = new TreeNode(val);
                q.offer(node.left);
            }

            if (i+1 < dataArray.length && !dataArray[i+1].equals("N")) {
                int val = Integer.parseInt(dataArray[i+1]);
                node.right = new TreeNode(val);
                q.offer(node.right);
            }
            i+=2;
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));