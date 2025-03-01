class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj_list(n);
        for (vector<int> edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        
        queue<int> q;
        vector<bool> visited(n);
        q.push(source);
        visited[source] = true;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            if (node == destination) return true;
            for (int neighbor : adj_list[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }
};