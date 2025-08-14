class Solution {
public:
    // Time Comp -> O(n)
    // Space Comp -> O(1)
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0, r = 0;
        double sum = 0, maxSum = INT_MIN;
        while (l <= r && r < nums.size()) {
            sum += nums[r];
            if ((r - l + 1) == k) {
                maxSum = max(maxSum, sum);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return maxSum / k;
    }
};