class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int l = 0, r = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            int square;
            if (abs(nums[l]) < abs(nums[r])) {
                square = nums[r];
                r--;
            } else {
                square = nums[l];
                l++;
            }
            result[i] = square * square;
        }
        return result;
    }
};