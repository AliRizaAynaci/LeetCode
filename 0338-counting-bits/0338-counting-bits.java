class Solution {
    public int[] countBits(int n) {
        // 2
        // 0, 1, 2 = 000, 001, 010
        // 5
        // 0, 1, 2, 3, 4, 5
        // 000, 001, 010, 011, 100, 101
        int[] dp = new int[n+1];
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
        // int[] counts = new int[n+1];
        // for (int i = 1; i < n+1; i++) {
        //     int num = i;
        //     int count = 0;
        //     while (num != 0) {
        //         count += num & 1;
        //         num = num >>> 1;
        //     }
        //     counts[i] = count;
        // }
        // return counts;
    }
}