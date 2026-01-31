class Solution {
    public static int maxArea(int[] heights) {
        int left = 0, right = heights.length-1;
        int maxArea = 0;
        while (left < right) {
            int minH = Math.min(heights[left], heights[right]);
            int area = minH * (right-left);
            maxArea = Math.max(maxArea, area);
            if (heights[left] < heights[right]) left++;
            else right--;
        }
        return maxArea;
    }
}