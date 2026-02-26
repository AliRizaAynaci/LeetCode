class Solution {
    private int[] topologicalSort(int[][] edges) {
        int n = edges.length;
        List<List<Integer>> adjList = new ArrayList<>();
        int[] indegrees = new int[n + 1];
        for (int i = 0; i < n+1; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adjList.get(edge[0]).add(edge[1]);
            adjList.get(edge[1]).add(edge[0]);
            indegrees[edge[0]]++;
            indegrees[edge[1]]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            if (indegrees[i] == 1) q.offer(i);
        }
        while (!q.isEmpty()) {
            int node = q.poll();
            indegrees[node]--;
            for (int nei : adjList.get(node)) {
                indegrees[nei]--;
                if (indegrees[nei] == 1) q.offer(nei);
            }
        }
        for (int i = n-1; i >= 0; i--) {
            int src = edges[i][0], nei = edges[i][1];
            if (indegrees[src] == 2 && indegrees[nei] > 0) {
                return new int[] {src, nei};
            }
        }
        return new int[0];
    }



    public int[] findRedundantConnection(int[][] edges) {
        return topologicalSort(edges);
    }
}
