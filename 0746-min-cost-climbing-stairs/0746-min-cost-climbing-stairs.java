class Solution {
    public static int minCostClimbingStairs(int[] cost) {
        int[] dp = new int[cost.length+1];
        Arrays.fill(dp, 0);
        for (int i = 2; i <= cost.length; i++) {
            dp[i] = Integer.min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[cost.length];
    }

    // public static int minCostClimbingStairs(int[] cost) {
    //     int[] dp = new int[cost.length];
    //     Arrays.fill(dp, -1);
    //     return Integer.min(helper(dp, cost, 0), helper(dp, cost, 1));
    // }

    // public static int helper(int[] dp, int[] cost, int i) {
    //     if (i >= cost.length) return 0;
    //     if (dp[i] != -1) return dp[i];
    //     dp[i] = cost[i] + Integer.min(helper(dp, cost, i+1), helper(dp, cost, i+2));
    //     return dp[i];
    // }
}