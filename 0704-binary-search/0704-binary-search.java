class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        if (n == 0) return -1;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (right + left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
}