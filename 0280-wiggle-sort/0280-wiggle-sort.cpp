class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int l = 0;
        // false -> smaller, true -> greater
        bool operation = false;
        while (l < nums.size() - 1) {
            if (!operation) { // for checking smaller
                if (nums[l] > nums[l+1]) {
                    swap(nums[l], nums[l+1]);
                }
                operation = true;
            } else { // for checking greater
                if (nums[l] < nums[l+1]) {
                    swap(nums[l], nums[l+1]);
                }
                operation = false;
            }
            l++;
        }
        
    }
};