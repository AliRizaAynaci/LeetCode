class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Time Comp -> O(n)
        // Space Comp -> O(1)
        if (nums.size() == 1) return nums[0];
        int currentSum = 0, maxSum = INT_MIN;
        for (int num : nums) {
            currentSum += num;
            maxSum = max(maxSum, currentSum);
            if (currentSum < 0) currentSum = 0;
        }
        return maxSum;
    }
};