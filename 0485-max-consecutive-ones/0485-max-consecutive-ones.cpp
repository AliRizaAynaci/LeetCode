class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
            } else if (nums[i] == 0) {
                count = 0;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};