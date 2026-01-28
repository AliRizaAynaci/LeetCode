class Solution {
    public static int maxProduct(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int maxProduct = 0, currMax = 1, currMin = 1;
        for (int i = 0; i < n; i++) {
            int prevMax = currMax * nums[i];
            currMax = Math.max(Math.max(currMax*nums[i], currMin*nums[i]), nums[i]);
            currMin = Math.min(Math.min(currMin*nums[i], prevMax), nums[i]);
            maxProduct = Math.max(maxProduct, currMax);
        }
        return maxProduct;
    }
}