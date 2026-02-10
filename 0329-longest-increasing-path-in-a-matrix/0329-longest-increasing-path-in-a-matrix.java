class Solution {
    private static int[][] dp;
    private static int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    private static int dfs(int[][] matrix, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i > m || j > n) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int maxLong = 1; // 1 for itself
        for (int[] dir : directions) {
            int row = dir[0] + i;
            int col = dir[1] + j;
            if (row >= 0 && row < m && col >= 0 && col < n && matrix[row][col] > matrix[i][j]) {
                int currentLong = dfs(matrix, row, col, m, n) + 1; // add 1 because each element is a path by itself
                maxLong = Math.max(maxLong, currentLong);
            }
        }
        dp[i][j] = maxLong;
        return maxLong;
    }

    public static int longestIncreasingPath(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        dp = new int[m][n];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        int longest = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int path = dfs(matrix, i, j, m, n);
                longest = Math.max(longest, path);
            }
        }
        return longest;
    }
}