class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& allPaths, vector<int>& path, int node) {
        path.push_back(node);
        if (node == graph.size() - 1) {
            allPaths.push_back(path);
        } else {
            for (int neighbor : graph[node]) {
                dfs(graph, allPaths, path, neighbor);
            }
        }
        path.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> allPaths;
        if (graph.empty()) return allPaths;
        vector<int> path;
        dfs(graph, allPaths, path, 0);
        return allPaths;
        // int n = graph.size();
        // queue<vector<int>> q;
        // q.push({0});

        // while (!q.empty()) {
        //     vector<int> path = q.front();
        //     q.pop();

        //     if (!path.empty() && path.back() == n - 1) {
        //         allPaths.push_back(path);
        //     } else {
        //         int lastNode = path.back();
        //         for (int neighbor : graph[lastNode]) {
        //             vector<int> newPath = path;
        //             newPath.push_back(neighbor);
        //             q.push(newPath);
        //         }
        //     }
        // }
        // return allPaths;
    }
};