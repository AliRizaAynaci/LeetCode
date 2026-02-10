/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    private static HashMap<Node, Node> visited;
    private static Node dfs(Node node) {
        if (node == null) return null;
        if (visited.containsKey(node)) return visited.get(node);
        Node clone = new Node(node.val);
        visited.put(node, clone);
        for (Node neighbour : node.neighbors) {
            clone.neighbors.add(dfs(neighbour));

        }
        return clone;
    }

    public static Node cloneGraph(Node node) {
        visited = new HashMap<>();
        return dfs(node);
    }
}