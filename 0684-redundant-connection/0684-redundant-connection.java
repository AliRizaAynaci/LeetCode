class Solution {
    private boolean dfs(List<List<Integer>> adjList, boolean[] visited, int node, int prev) {
        if (visited[node]) return true;
        visited[node] = true;
        for (int neighbour : adjList.get(node)) {
            if (neighbour == prev) continue;
            if (dfs(adjList, visited, neighbour, node)) {
                return true;
            }
        }
        return false;
    }
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            adjList.get(u).add(v);
            adjList.get(v).add(u);
            boolean[] visit = new boolean[n + 1];

            if (dfs(adjList, visit, u, -1)) {
                return edge;
            }
        }
        return new int[] {};
    }
}