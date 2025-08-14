class Solution {
public:
    // Time Comp -> O(n)
    // Space Comp -> O(1)
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 0, maxProfit = 0, profit = 0;
        while (left <= right && right < prices.size()) {
            while (prices[left] > prices[right]) {
                left++;
            }
            profit = prices[right] - prices[left];
            maxProfit = max(maxProfit, profit);
            right++;
        }
        return maxProfit;
    }
};