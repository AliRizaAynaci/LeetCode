class Solution {
    private static int calculateArea(int[][] grid, int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] < 1) return 0;
        grid[i][j] = -1;
        int left = calculateArea(grid, i, j-1, n, m);
        int right = calculateArea(grid, i, j+1, n, m);
        int up = calculateArea(grid, i-1, j, n, m);
        int down = calculateArea(grid, i+1, j, n, m);
        return left + right + up + down + 1;
    }
    public int maxAreaOfIsland(int[][] grid) {
        if (grid.length == 0) return 0;
        int n = grid.length, m = grid[0].length;
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int area = calculateArea(grid, i, j, n, m);
                maxArea = Integer.max(maxArea, area);
            }
        }
        return maxArea;
    }
}