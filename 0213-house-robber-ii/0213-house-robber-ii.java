class Solution {
    int[] memo;

    // private int dfs(int[] nums, int i, int n) {
    //     if (i >= n) return 0;
    //     if (memo[i] != -1) return memo[i];
    //     int taken = nums[i] + dfs(nums, i+2, n);
    //     int skip = dfs(nums, i+1, n);
    //     memo[i] = Math.max(taken, skip);
    //     return memo[i];
    // }

    private int helper(int[] nums, int i, int n) {
        if (i >= n) return 0;
        int prev1 = 0, prev2 = 0;
        for (int j = i; j < n; j++) {
            int curr = Math.max(nums[j] + prev1, prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }

    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 1) return nums[0];
        memo = new int[n];
        Arrays.fill(memo, -1);
        // int leftSub = dfs(nums, 0, n-1);
        // Arrays.fill(memo, -1);
        // int rightSub = dfs(nums, 1, n);
        // return Math.max(leftSub, rightSub);
        return Math.max(helper(nums, 0, n-1), helper(nums, 1, n));
    }
}
