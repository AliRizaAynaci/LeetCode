class Solution {
    private static int binarySearch(List<Integer> dp, int num) {
        int left = 0, right = dp.size()-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (dp.get(mid) > num) {
                right = mid-1;
            } else if (dp.get(mid) < num) {
                left = mid+1;
            } else {
                return mid;
            }
        }
        return -(left + 1);
    }

    public static int lengthOfLIS(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        List<Integer> dp = new ArrayList<>();
        dp.add(nums[0]);
        int LIS = 1;
        for (int i = 1; i < nums.length; i++) {
            if (dp.get(dp.size()-1) < nums[i]) {
                dp.add(nums[i]);
                LIS++;
                continue;
            }
            int idx = binarySearch(dp, nums[i]);
            if (idx < 0) idx = -(idx + 1);
            if (idx == dp.size()) {
                dp.add(nums[i]);
            } else {
                dp.set(idx, nums[i]);
            }
        }
        return LIS;
    }
}