class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
      // Create a graph where each node represents a garden and each edge
      // represents a path between two gardens.
      vector<vector<int>> graph(n);
      for (const auto& path : paths) {
        int x = path[0] - 1;
        int y = path[1] - 1;
        graph[x].push_back(y);
        graph[y].push_back(x);
      }

      // Create a vector of flower types, where initially all gardens are empty.
      vector<int> flowers(n);

      // For each garden, assign it a flower type that is different from the
      // flower types of the gardens connected to it.
      for (int i = 0; i < n; i++) {
        unordered_set<int> used;
        for (int j : graph[i]) {
          used.insert(flowers[j]);
        }
        for (int t = 1; t <= 4; t++) {
          if (!used.count(t)) {
            flowers[i] = t;
            break;
          }
        }
      }

      return flowers;        
    }
};