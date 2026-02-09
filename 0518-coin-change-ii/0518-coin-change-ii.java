class Solution {
    private static int dfs(int amount, int[] coins,Integer[][] memo, int index){
        if (index >= coins.length || amount < 0) return 0;
        if (index == 0) return amount % coins[0] == 0 ? 1 : 0;
        if (amount == 0) return 1;
        if (memo[index][amount] != null) return memo[index][amount];
        int skip = dfs(amount, coins, memo, index - 1);
        int take = 0;
        if (amount >= coins[index]){
            take = dfs(amount - coins[index], coins, memo, index);
        }
        memo[index][amount] = take+skip;
        return memo[index][amount];
    }

    public static int change(int amount, int[] coins) {
        Integer[][] memo = new Integer[coins.length][amount+1];
        return dfs(amount, coins, memo, coins.length-1);
    }
}