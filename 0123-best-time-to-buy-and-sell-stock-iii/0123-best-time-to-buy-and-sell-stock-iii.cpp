class Solution {
public:
    // Time Comp -> O(n)
    // Space Comp -> O(n)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> leftMaxProfit(n, 0);
        vector<int> rightMaxProfit(n+1, 0);

        int minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            leftMaxProfit[i] = max(leftMaxProfit[i-1], prices[i] - minPrice);
        }

        int maxPrice = prices[n-1];
        for (int i = n-2; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            rightMaxProfit[i] = max(rightMaxProfit[i+1], maxPrice - prices[i]);
        }

        int maxProfit = 0;
        for (int i = 0; i< n; i++) {
            maxProfit = max(maxProfit, leftMaxProfit[i] + rightMaxProfit[i]);
        }

        return maxProfit;
    }
};
