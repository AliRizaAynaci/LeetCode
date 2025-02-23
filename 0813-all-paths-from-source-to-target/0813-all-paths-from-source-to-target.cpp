class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> allPaths;
        if (graph.empty()) return allPaths;

        int n = graph.size();
        queue<vector<int>> q;
        q.push({0});

        while (!q.empty()) {
            vector<int> path = q.front();
            q.pop();

            if (!path.empty() && path.back() == n - 1) {
                allPaths.push_back(path);
            } else {
                int lastNode = path.back();
                for (int neighbor : graph[lastNode]) {
                    vector<int> newPath = path;
                    newPath.push_back(neighbor);
                    q.push(newPath);
                }
            }
        }
        return allPaths;
    }
};