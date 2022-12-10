class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int largest = 0;
        int smaller = prices[0];
        for(int i = 0; i < prices.size(); i++){
            
            smaller = min(smaller, prices[i]);
            int diff = prices[i] - smaller;
            largest = max(largest, diff);
        }
        return largest;
    }
};