class Solution {
public:
    // Time Comp -> O(n)
    // Space Comp -> O(1)
    int maxAscendingSum(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int currentSum = nums[0], maxSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                currentSum += nums[i];
            } else {
                currentSum = nums[i];
            }
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};