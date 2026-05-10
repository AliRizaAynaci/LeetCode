class Solution {
    public boolean containsDuplicate(int[] nums) {
        int n = nums.length;
        if (n == 0) return false;
        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            if (set.contains(nums[i])) return true;
            set.add(nums[i]);
        }
        return false;
    }
}