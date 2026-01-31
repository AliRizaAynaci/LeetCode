class Solution {
    // Time: O(n), Space: O(1)
    public static int trap(int[] height) {
        int len = height.length;
        int left = 0, right = len-1;
        int res = 0;
        int maxLeft = height[left], maxRight = height[right];
        while (left < right) {
            if (maxLeft < maxRight) {
                left++;
                maxLeft = Math.max(maxLeft, height[left]);
                res += maxLeft - height[left];
            } else {
                right--;
                maxRight = Math.max(maxRight, height[right]);
                res += maxRight - height[right];
            }
        }
        return res;
    }
}