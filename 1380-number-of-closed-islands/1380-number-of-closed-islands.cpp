class Solution {
private:
    bool isClosedIsland(vector<vector<int>>& grid, int i, int j, int rows, int cols) {
        // -1 -> visited points
        // 1 -> water, 0 -> land 
        if (grid[i][j] == -1 || grid[i][j] == 1) return true;
        if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) return false;
        grid[i][j] = -1;
        bool left = isClosedIsland(grid, i, j - 1, rows, cols);
        bool right = isClosedIsland(grid, i, j + 1, rows, cols);
        bool up = isClosedIsland(grid, i - 1, j, rows, cols);
        bool down = isClosedIsland(grid, i + 1, j, rows, cols);
        return left && right && up && down;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int closedIslands = 0, rows = grid.size(), cols = grid[0].size();
        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {
                if (grid[i][j] == 0) {
                    if (isClosedIsland(grid, i, j, rows, cols)) closedIslands++;
                }
            }
        }
        return closedIslands;
    }
};