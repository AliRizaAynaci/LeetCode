class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int n = numbers.length;
        if (n == 0) return new int[] {};
        int left = 0, right = n-1;
        while (right > left) {
            if (numbers[left] + numbers[right] == target) return new int[] {left+1, right+1};
            else if (numbers[left] + numbers[right] < target) left++;
            else right--;
        }
        return new int[] {};
    }
}