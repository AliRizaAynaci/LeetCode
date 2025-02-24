class Solution {
private:
    const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void markBoard(vector<vector<char>>& board, int m, int n, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') return;
        board[i][j] = 'T'; // temporary marked
        for (auto [dx, dy] : directions) {
            int x = i + dx, y = j + dy;
            markBoard(board, m, n, x, y);
        }
    }

    void flipBoard(vector<vector<char>>& board, int m, int n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }


public:
    void solve(vector<vector<char>>& board) {
        if (board.size() <= 1) return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            markBoard(board, m, n, i, 0); // left border
            markBoard(board, m, n, i, n - 1); // right border
        }

        for (int i = 0; i < n; i++) {
            markBoard(board, m, n, 0, i); // top border
            markBoard(board, m, n, m - 1, i); // bottom border
        }

        flipBoard(board, m, n);
    }  
};