class Solution {
    private static int helper(int[] nums, int start, int end) {
        int len = end - start + 1;
        if (len <= 0) return 0;
        int[] dp = new int[len+1];
        dp[0] = 0;
        dp[1] = nums[start];
        for (int i = 2; i <= len; i++) {
            dp[i] = Math.max(dp[i-1], nums[start+i-1] + dp[i-2]);
        }
        return dp[len];
    }

    public static int rob(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return Math.max(helper(nums, 0, n-2), helper(nums, 1, n-1));
    }
}