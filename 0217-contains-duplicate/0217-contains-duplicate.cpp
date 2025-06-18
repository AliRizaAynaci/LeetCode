class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set;

        for (int i = 0; i < n; i++) {
            if (set.find(nums[i]) != set.end()) {
                return true;
            }
            set.insert(nums[i]);
        }
        return false;
    }
};