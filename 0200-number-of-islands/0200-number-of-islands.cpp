class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int island_counter = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    island_counter++;
                }
            }
        }
        return island_counter;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        // 1) out of bounds
        // 2) grid[i][j] == 0
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i, j - 1, m, n);
        dfs(grid, i, j + 1, m, n);
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i + 1, j, m, n);
    }
};