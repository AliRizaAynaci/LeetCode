class Solution {
    public static int ways(int[] dp, String s, int i) {
        if (i == s.length()) return 1;
        if (s.charAt(i) == '0') return 0;
        if (dp[i] != -1) return dp[i];
        dp[i] = ways(dp, s, i+1);
        if (i + 2 <= s.length()) {
            String even = s.substring(i, i+2);
            int num = Integer.parseInt(even);
            if (num >= 10 && num <= 26) {
                dp[i] += ways(dp, s, i+2);
            }
        }
        return dp[i];
    }

    public static int numDecodings(String s) {
        int n = s.length();
        // each idx in the dp array holds the count of different ways until the idx
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        return ways(dp, s, 0);
    }
}
