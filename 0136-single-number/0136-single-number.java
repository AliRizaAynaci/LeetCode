class Solution {
    public int singleNumber(int[] nums) {
        int res = 0b000_000;
        for (int num : nums) {
            res ^= num;
        }
        return res;
    }
}