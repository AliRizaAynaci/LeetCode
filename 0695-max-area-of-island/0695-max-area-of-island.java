class Solution {
    private int dfs(int[][] grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) {
            return 0;
        }
        // mark as visited
        grid[i][j] = -1;
        int l = dfs(grid, i, j-1, m, n);
        int r = dfs(grid, i, j+1, m, n);
        int u = dfs(grid, i-1, j, m, n);
        int d = dfs(grid, i+1, j, m, n);
        return l + r + u + d + 1;
    }

    public int maxAreaOfIsland(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int currentArea = dfs(grid, i, j, m, n);
                    maxArea = Math.max(maxArea, currentArea);
                }
            }
        }
        return maxArea;
    }
}