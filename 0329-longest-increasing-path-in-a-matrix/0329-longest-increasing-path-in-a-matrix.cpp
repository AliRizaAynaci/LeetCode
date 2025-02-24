class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return 0;
        int n = matrix.size(), m = matrix[0].size(), longestPathSize = 0;
        vector<vector<int>> cache(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int longest = getLongestPath(matrix, cache, i, j, n, m);
                longestPathSize = max(longestPathSize, longest);
            }
        }
        return longestPathSize;
    }

    int getLongestPath(vector<vector<int>>& matrix, vector<vector<int>>& cache, int i, int j, int n, int m) {
        if (cache[i][j] > 0) return cache[i][j];
        int maxPath = 0;
        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        for (auto [dx, dy] : directions) {
            int x = i + dx, y = j + dy;
            if (x > -1 && y > -1 && x < n && y < m && matrix[x][y] > matrix[i][j]) {
                int longestPath = getLongestPath(matrix, cache, x, y, n, m);
                maxPath = max(maxPath, longestPath);
            }
        }
        cache[i][j] = maxPath + 1;
        return cache[i][j];
    }
};