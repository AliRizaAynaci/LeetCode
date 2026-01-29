class Solution {
    private static boolean dfs(Boolean[][] dp, int[] nums, int i, int target) {
        if (i == nums.length) return target == 0;
        if (target < 0) return false;
        if (dp[i][target] != null) return dp[i][target];
        dp[i][target] = dfs(dp, nums, i+1, target) ||
                dfs(dp, nums, i+1, target - nums[i]);
        return dp[i][target];
    }

    public static boolean canPartition(int[] nums) {
        if (nums.length <= 1) return false;
        int sum = sum(nums);
        if (sum % 2 != 0) return false;
        int target = sum/2;
        Boolean[][] dp = new Boolean[nums.length][target + 1];
        for (int i = 0; i < nums.length; i++) {
            dp[i][0] = true;
        }
        return dfs(dp, nums, 0, target);
    }

    private static int sum(int[] nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return sum;
    }
}