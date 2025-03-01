class Solution {
private:
    bool dfs(vector<vector<int>>& maze, int m, int n,int i, int j, vector<int>& destination,
            vector<vector<bool>>& seen) {
        
        if (seen[i][j]) return false;
        if (i == destination[0] && j == destination[1]) return true;
        seen[i][j] = true;
        vector<int> dirX{0, 1, 0, -1};
        vector<int> dirY{-1, 0, 1, 0};

        for (int d = 0; d < 4; d++) {
            int r = i, c = j;
            while (r >= 0 && r < m && c >= 0 && c < n && maze[r][c] == 0) {
                r += dirX[d];
                c += dirY[d];
            }
            if (dfs(maze, m, n, r - dirX[d], c - dirY[d], destination, seen)) {
                return true;
            }
        }
        return false;
    }

public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n));
        return dfs(maze, m, n, start[0], start[1], destination, seen);
        
    }
};