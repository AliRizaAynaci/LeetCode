class Solution {
private:
    int getArea(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) return 0;
        // if we come here, we know the current position is 1
        grid[i][j] = 0;
        int left = getArea(grid, i, j - 1, m, n);
        int right = getArea(grid, i, j + 1, m, n);
        int up = getArea(grid, i + 1, j, m, n);
        int down = getArea(grid, i - 1, j, m, n);
        return left + right + up + down + 1; 
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSum = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = getArea(grid, i, j, m, n);
                    maxSum = max(maxSum, area);
                }
            }
        }
        return maxSum;
    }
};