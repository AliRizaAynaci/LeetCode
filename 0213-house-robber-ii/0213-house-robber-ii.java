class Solution {
    private static int helper(int[] nums, int start, int end) {
        int len = end - start + 1;
        if (len == 0 ) return 0;
        if (len == 1) return nums[start];
        int[] dp = new int[len];
        dp[0] = nums[start];
        dp[1] = Math.max(nums[start], nums[start+1]);
        for (int i = 2; i < len; i++) {
            dp[i] = Math.max(dp[i-1], nums[start+i] + dp[i-2]);
        }
        return dp[len-1];
    }

    public static int rob(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return Math.max(helper(nums, 0, n-2), helper(nums, 1, n-1));
    }
}