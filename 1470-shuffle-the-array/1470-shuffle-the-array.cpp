class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int size = nums.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(nums[i]);
            result.push_back(nums[i+n]);
        }
        return result;
    }
};
