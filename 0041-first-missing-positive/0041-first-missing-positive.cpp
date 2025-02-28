class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) return 1;

        int length = nums.size(), containsOne = 0;
        for (int i = 0; i < length; i++) {
            if (nums[i] == 1) {
                containsOne = 1;
            } else if (nums[i] <= 0 || nums[i] > length) {
                nums[i] = 1;
            }
        }

        if (containsOne == 0) return 1;

        for (int i = 0; i < length; i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) nums[index] = -1 * nums[index];
        }

        for (int i = 0; i < length; i++) {
            if (nums[i] > 0) return i + 1;
        }

        return length + 1;
    }
};