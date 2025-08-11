class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        seen[0] = -1;
        int runningSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            int runningMod = runningSum % k;
            if (seen.find(runningMod) != seen.end()) {
                if (i - seen[runningMod] >= 2) return true;
            } else {
                seen[runningMod] = i;
            }
        }
        return false;
    }
};