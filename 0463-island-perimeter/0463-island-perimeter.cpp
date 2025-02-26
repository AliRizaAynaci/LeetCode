class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int& count) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
            count++;
            return;
        }
        if (grid[i][j] == -1) {
            return;
        }
        grid[i][j] = -1;
        dfs(grid, i, j - 1, m, n, count);
        dfs(grid, i, j + 1, m, n, count);
        dfs(grid, i - 1, j, m, n, count);
        dfs(grid, i + 1, j, m, n, count);
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int perimeter = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    // Her kara hücresi için 4 kenar başlangıçta sayılır
                    perimeter += 4;
                    
                    // Eğer solunda bir kara hücresi varsa, ortak kenar düşmeli
                    if (j > 0 && grid[i][j - 1] == 1) perimeter -= 2;
                    
                    // Eğer yukarısında bir kara hücresi varsa, ortak kenar düşmeli
                    if (i > 0 && grid[i - 1][j] == 1) perimeter -= 2;
                }
            }
        }
        return perimeter;
    }
};