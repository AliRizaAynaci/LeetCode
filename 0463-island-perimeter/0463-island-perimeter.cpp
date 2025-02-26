class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int& count) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
            count++;
            return;
        }
        if (grid[i][j] == -1) {
            return;
        }
        grid[i][j] = -1;
        dfs(grid, i, j - 1, m, n, count);
        dfs(grid, i, j + 1, m, n, count);
        dfs(grid, i - 1, j, m, n, count);
        dfs(grid, i + 1, j, m, n, count);
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, m, n, count);
                }
            }
        }
        return count;
    }
};