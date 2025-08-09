class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        int count = 0;
        unordered_map<int, int> freq;
        freq[0]++;
        for (int i = 0; i < n; i++) {
            int runningSum = prefix[i];
            int diff = runningSum - k;
            if (freq.find(diff) != freq.end()) {
                count += freq[diff];
            }
            freq[runningSum]++;
        }
        return count;
        
    }
};