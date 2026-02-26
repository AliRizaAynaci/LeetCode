class Solution {
    private boolean dfsCycleDetection(List<List<Integer>> adj, boolean[] visited, int src, int parent) {
        if (visited[src]) return true;
        visited[src] = true;
        for (int nei : adj.get(src)) {
            if (nei == parent) continue;
            if (dfsCycleDetection(adj, visited, nei, src)) return true;
        }
        return false;
    }

    public int[] cycleDetection(int[][] edges) {
        int n = edges.length;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n+1; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            int src = edge[0], nei = edge[1];
            adj.get(src).add(nei);
            adj.get(nei).add(src);
            boolean[] visited = new boolean[n+1];
            if (dfsCycleDetection(adj, visited, src, -1)) return edge;
        }
        return new int[0];
    }



    public int[] findRedundantConnection(int[][] edges) {
        return cycleDetection(edges);
    }
}