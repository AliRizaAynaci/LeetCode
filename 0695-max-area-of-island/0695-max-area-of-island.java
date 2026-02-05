class Solution {
    private static int calculateArea(int[][] grid, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1) return 0;
        grid[i][j] = -1; // mark as visited
        int left = calculateArea(grid, i, j-1, m, n);
        int right = calculateArea(grid, i, j+1, m, n);
        int up = calculateArea(grid, i-1, j, m, n);
        int down = calculateArea(grid, i+1, j, m, n);
        return left + right + up + down + 1;
    }

    public static int maxAreaOfIsland(int[][] grid) {
        int m = grid.length;
        if (m == 0) return 0;
        int n = grid[0].length;
        int largestArea = 0;
        for (int i = 0; i<m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = calculateArea(grid, i, j, m, n);
                    largestArea = Math.max(largestArea, area);
                }
            }
        }
        return largestArea;
    }
}