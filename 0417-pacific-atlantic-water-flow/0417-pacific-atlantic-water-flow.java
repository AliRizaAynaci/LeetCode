class Solution {
    boolean[][] pacific;
    boolean[][] atlantic;
    int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    private void dfs(int[][] heights, int i, int j, int m, int n, int prevHeight, boolean[][] visited) {
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (heights[i][j] < prevHeight) return;
        if (visited[i][j]) return;
        visited[i][j] = true;
        for (int[] dir : directions) {
            dfs(heights, i + dir[0], j + dir[1], m, n, heights[i][j], visited);
        }
    }

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int m = heights.length;
        if (m == 0) return new ArrayList<>();
        int n = heights[0].length;
        List<List<Integer>> res = new ArrayList<>();
        pacific = new boolean[m][n];
        atlantic = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, m, n, heights[i][0], pacific);
            dfs(heights, i, n - 1,m, n, heights[i][n - 1], atlantic);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, 0, j, m, n, heights[0][j], pacific);
            dfs(heights, m - 1, j, m, n, heights[m - 1][j], atlantic);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.add(Arrays.asList(i, j));
                }
            }
        }
        return res;
    }
}