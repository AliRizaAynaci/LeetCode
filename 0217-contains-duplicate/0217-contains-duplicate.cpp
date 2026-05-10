class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return false;
        unordered_set<int> set;
        for (int i = 0; i < n; i++) {
            if (set.count(nums[i])) return true;
            set.insert(nums[i]);
        }
        return false;
    }
};