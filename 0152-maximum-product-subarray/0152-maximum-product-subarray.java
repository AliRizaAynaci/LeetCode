class Solution {
    public static int maxProduct(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int[][] dp = new int[n][2];
        dp[0][0] = nums[0]; // 2, 6, -2, 4
        dp[0][1] = nums[0]; // 2, 3, -12, -48
        int maxProduct = nums[0];
        // dp[i][0] = maxProduct, dp[i][1] = minProduct
        for (int i = 1; i < n; i ++) {
            // for max
            dp[i][0] = Math.max(nums[i], Math.max(dp[i-1][0] * nums[i], dp[i-1][1] * nums[i]));
            // for min
            dp[i][1] = Math.min(nums[i], Math.min(dp[i-1][0] * nums[i], dp[i-1][1] * nums[i]));
            maxProduct = Math.max(maxProduct, dp[i][0]);
        }
        return maxProduct;
    }
}