class Solution {
    // Time Complexity : O(N * M), where N is size of grid's rows and M is size of grid's columns
    // Space Complexity : O(N * M), because we call the recursive function throughout the grid
    // and it use the stack for every recursive call
private:
    int getArea(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] < 1) {
            return 0;
        }
        grid[i][j] = -1; // visited
        int left = getArea(grid, i, j - 1, m, n);
        int right = getArea(grid, i, j + 1, m, n);
        int up = getArea(grid, i - 1, j, m, n);
        int down = getArea(grid, i + 1, j, m, n);
        return left + right + up + down + 1;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();
        int maxArea= 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int area = getArea(grid, i, j, m ,n);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};