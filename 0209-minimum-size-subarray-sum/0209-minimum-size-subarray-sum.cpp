class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, sum = 0, minSize = INT_MAX;
        while (right < n) {
            sum += nums[right];
            while (sum >= target) {
                minSize = min(minSize, (right-left+1));
                sum -= nums[left];
                left++;
            }
            right++;
        }
        if (minSize == INT_MAX) return 0;
        return minSize;
    }
};