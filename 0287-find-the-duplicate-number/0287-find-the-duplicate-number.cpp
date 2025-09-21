class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Time Comp: O(n)
        // Space Comp: O(1)
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) return abs(nums[i]);
            nums[index] = -nums[index];
        }
        return -1;
        
        // Time Comp : O(2*N) -> O(N)
        // Space : O(1)
        
        // sort (nums.begin(), nums.end());
        // for (int i=1; i < nums.size(); i++) {
        //     if (nums[i] == nums[i-1]) return nums[i];
        // }
        // return -1;
    }
};