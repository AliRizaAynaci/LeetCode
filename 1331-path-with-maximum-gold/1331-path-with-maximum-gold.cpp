class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int maxSum = 0, m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    int gold = findMaxGold(grid, i, j, m, n, visited);
                    maxSum = max(maxSum, gold);
                }
            }
        }
        return maxSum;
    }

    int findMaxGold(vector<vector<int>>& grid, int i, int j, int m, int n, 
                                            vector<vector<bool>>& visited) {
        // 1- out of bounds
        // 2- visited[i][j] = true 
        // 3- grid[i][j] = 0
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 || visited[i][j]) return 0;
        visited[i][j] = true;
        int left = findMaxGold(grid, i, j - 1, m, n, visited);
        int right = findMaxGold(grid, i, j + 1, m, n, visited);
        int up = findMaxGold(grid, i - 1, j, m, n, visited);
        int down = findMaxGold(grid, i + 1, j, m, n, visited);
        visited[i][j] = false;
        return max(left, max(right, max(up, down))) + grid[i][j];
    }
};