class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1) return 0;

        sort(nums.begin(), nums.end());
        int gap = 0;
        for (int i = 1; i < nums.size(); i++) {
            int difference = nums[i] - nums[i - 1];
            gap = max(gap, difference);
        }
        return gap;
    }
};