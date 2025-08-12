class Solution {
public:
    // Time Comp -> O(n)
    // Space Comp -> O(n)
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        freq[0]++;
        int runningSum = 0, count = 0;
        for (int i = 0; i < n; i++) {
            runningSum += nums[i];
            int diff = runningSum - k;
            if (freq.find(diff) != freq.end()) {
                count += freq[diff];
            }
            freq[runningSum]++;
        }
        return count;
    }
};