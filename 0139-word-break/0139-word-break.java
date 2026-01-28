class Solution {
    public static boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        if (n == 0) return false;
        boolean[] dp = new boolean[n+1];
        dp[n] = true;
        for (int i = n-1; i >= 0; i--) {
            for (String word : wordDict) {
                int len = i + word.length();
                if ((len <= n) && s.substring(i, len).equals(word)) {
                    dp[i] = dp[len];
                }
                if (dp[i]) {
                    break;
                }
            }
        }
        return dp[0];
    }
}