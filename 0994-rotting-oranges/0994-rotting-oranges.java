class Solution {
    public static int orangesRotting(int[][] grid) {
        if (grid.length == 0) return 0;
        int m = grid.length, n = grid[0].length;
        int minute = 0, freshOranges = 0;
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) freshOranges++;
                if (grid[i][j] == 2) q.offer(new int[] {i, j});
            }
        }
        int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.isEmpty() && freshOranges > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int[] direction = q.poll();
                int r = direction[0], c = direction[1];
                for (int[] d : directions) {
                    int row = d[0] + r;
                    int col = d[1] + c;
                    if (row >= 0 && col >= 0 && row < m && col < n && grid[row][col] == 1) {
                        grid[row][col] = 2;
                        q.offer(new int[] {row, col});
                        freshOranges--;
                    }
                }
            }
            minute++;
        }
        return freshOranges == 0 ? minute : -1;
    }
}