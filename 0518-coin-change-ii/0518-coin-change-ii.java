class Solution {
    private static int dfs(int amount, int[] coins,Integer[][] memo, int index){
        if (index == coins.length || amount < 0) return 0;
        if (amount == 0) return 1;
        if (memo[index][amount] != null) return memo[index][amount];
        int take = dfs(amount - coins[index], coins, memo, index);
        int skip = dfs(amount, coins, memo, index+1);
        memo[index][amount] = take + skip;
        return memo[index][amount];
    }

    public static int change(int amount, int[] coins) {
        Integer[][] memo = new Integer[coins.length][amount+1];
        return dfs(amount, coins, memo, 0);
    }
}