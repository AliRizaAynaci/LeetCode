class Solution {

    // Time Comp: O(N)
    // Space Comp: O(1)
    public static int climbStairs(int n) {
        int first = 1, second = 1;
        for (int i = 0; i < n-1; i++) {
            int tmp = first;
            first = first + second;
            second = tmp;
        }
        return first;
    }

    // Time Comp: O(n)
    // Space Comp: O(n)
    // public static int climbStairs(int n ) {
    //     if (n <= 2) return n;
    //     int[] dp = new int[n+1];
    //     dp[1] = 1;
    //     dp[2]= 2;
    //     for (int i = 3; i <= n; i++) {
    //         dp[i] = dp[i-1] + dp[i-2];
    //     }
    //     return dp[n];
    // }
}