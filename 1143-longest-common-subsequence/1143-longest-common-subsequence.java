class Solution {
    private static int dfs(int[][] dp, String s1, String s2, int idx1, int idx2) {
        if (idx1 < 0 || idx2 < 0) return 0;
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if (s1.charAt(idx1) == s2.charAt(idx2)) return 1 + dfs(dp, s1, s2, idx1-1, idx2-1);
        dp[idx1][idx2] = Math.max(dfs(dp, s1, s2, idx1-1, idx2), dfs(dp, s1, s2, idx1, idx2-1));
        return dp[idx1][idx2];
    }

    public static int longestCommonSubsequence(String text1, String text2) {
        int len1 = text1.length(), len2 = text2.length();
        int[][] dp = new int[len1][len2];
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                dp[i][j] = -1;
            }
        }
        return dfs(dp, text1, text2, len1-1, len2-1);
    }
}