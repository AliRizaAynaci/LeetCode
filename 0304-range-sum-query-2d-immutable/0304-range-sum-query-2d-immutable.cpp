class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        prefix.assign(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = (i > 0) ? prefix[i-1][j] : 0;
                int left = (j > 0) ? prefix[i][j-1] : 0;
                int diag = (i > 0 && j > 0) ? prefix[i-1][j-1] : 0;
                prefix[i][j] = matrix[i][j] + up + left - diag;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        long long res = prefix[row2][col2];
        if (row1 > 0) res -= prefix[row1-1][col2];
        if (col1 > 0) res -= prefix[row2][col1-1];
        if (row1 > 0 && col1 > 0) res += prefix[row1-1][col1-1];
        return (int)res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */