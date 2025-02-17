class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int top = i - 1 < 0 ? INT_MAX : grid[i-1][j];
                int bottom = j - 1 < 0 ? INT_MAX : grid[i][j-1];
                int minVal = top == INT_MAX && bottom == INT_MAX ? 0 : min(top, bottom);
                grid[i][j] += minVal;
            }
        }
        return grid[n-1][m-1];
    }
};