class Solution {
    public static int minCostClimbingStairs(int[] cost) {
        int[] dp = new int[cost.length];
        Arrays.fill(dp, -1);
        return Integer.min(helper(dp, cost, 0), helper(dp, cost, 1));
    }

    public static int helper(int[] dp, int[] cost, int i) {
        if (i >= cost.length) return 0;
        if (dp[i] != -1) return dp[i];
        dp[i] = cost[i] + Integer.min(helper(dp, cost, i+1), helper(dp, cost, i+2));
        return dp[i];
    }
}