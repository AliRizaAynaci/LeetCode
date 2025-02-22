class Solution {
    // Time Complexity : O(N * M)
    // Space Complexity :
    //          Solution 1 -> O(N * M) where N is the size of columns and M is the size of rows
    //          Solution 2 -> O(N), where is the N size of columns
public:
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n));
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (i == 0 || j == 0) dp[i][j] = 1;
    //             else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    //         }
    //     }
    //     return dp[m - 1][n - 1];
    // }
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j - 1] + dp[j];
            }
        }
        return dp[n - 1];
    }
};