class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, right = 0;
        int zeroCount = 0, maxLength = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};