class Solution {
private:
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int getIslandSize(vector<vector<int>>& grid, int i, int j, int m, int n, int islandID) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1) return 0;
        grid[i][j] = islandID;
        int left = getIslandSize(grid, i, j - 1, m, n, islandID);
        int right = getIslandSize(grid, i, j + 1, m, n, islandID);
        int up = getIslandSize(grid, i - 1, j, m, n, islandID);
        int down = getIslandSize(grid, i + 1, j, m, n, islandID);
        return left + right + up + down + 1;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int large = 0, islandID = 2, m = grid.size(), n = grid[0].size();
        unordered_map<int, int> mp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = getIslandSize(grid, i, j, m, n, islandID);
                    large = max(large, size);
                    mp[islandID++] = size;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> set;
                    for (auto [dx, dy] : directions) {
                        int x = i + dx, y = j + dy;
                        if (x > -1 && y > -1 && x < m && y < n && grid[x][y] != 0) {
                            set.insert(grid[x][y]);
                        }
                    }
                    int sum = 1;
                    for (int num : set) {
                        sum += mp[num];
                    }
                    large = max(large, sum);
                }
            }
        }
        return large;
    }
};