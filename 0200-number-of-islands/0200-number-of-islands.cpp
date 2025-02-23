class Solution {
private:
    /**
     * Breadth-First Search (BFS) Approach
     * ----------------------------------
     * - Uses a queue to explore the grid level by level (iterative).
     * - Processes all neighboring land ('1') before moving to the next level.
     * - Marks visited land as '0' to avoid revisiting.
     * 
     * Time Complexity: O(M × N) → Every cell is visited once.
     * Space Complexity: O(min(M, N)) → At most, one row/column can be in the queue.
     */
    void bfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            pair<int, int> p = q.front(); q.pop();
            int k = p.first, l = p.second;
            for (auto [dx, dy] : directions) {
                int x = k + dx, y = l + dy;
                if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == '1') {
                    q.push({x, y});
                    grid[x][y] = '0';
                }
            }
        }
    }

    /**
     * Depth-First Search (DFS) Approach
     * ---------------------------------
     * - Uses recursion to explore deeply before backtracking.
     * - Moves in one direction until it can't continue, then backtracks.
     * - Marks visited land as '0' to avoid revisiting.
     * 
     * Time Complexity: O(M × N) → Every cell is visited once.
     * Space Complexity: O(M × N) in the worst case (if all land is connected, stack grows deep).
     */
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        // 1) out of bounds
        // 2) seen
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i, j - 1, m, n);
        dfs(grid, i, j + 1, m, n);
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i + 1, j, m, n);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int island = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    island++;
                }
            }
        }
        return island;
    }
};