class Solution {
    // Time: O(n), Space: O(k)
    public static int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        if (n < k) return new int[] {};
        Deque<Integer> deque = new LinkedList<>();
        int[] res = new int[n - k + 1];
        int resIdx = 0;
        for (int i = 0; i < n; i++) {
            if (!deque.isEmpty() && deque.peekFirst() < i-k+1) {
                deque.pollFirst();
            }
            while (!deque.isEmpty() && nums[deque.peekLast()] < nums[i]){
                deque.pollLast();
            }
            deque.offerLast(i);
            if (i >= k - 1) {
                res[resIdx] = nums[deque.peekFirst()];
                resIdx++;
            }
        }
        return res;
        // int n = nums.length;
        // if (n < k) {
        //     return new int[] {};
        // }
        // int[] res = new int[n-k+1];
        // Deque<Integer> dq = new LinkedList<>();
        // int left = 0 , right = 0;
        // while (right < k) {
        //     while (!dq.isEmpty() && dq.peekLast() < nums[right]) {
        //         dq.pollLast();
        //     }
        //     dq.offerLast(nums[right]);
        //     right++;
        // }
        // res[left] = dq.peekFirst();
        // left++;
        // while (right < n) {

        //     int num = nums[right];
        //     if (!dq.isEmpty() && nums[left-1] == dq.peekFirst()) {
        //         dq.pollFirst();
        //     }
        //     while (!dq.isEmpty() && dq.peekLast() < num) {
        //         dq.pollLast();
        //     }
        //     dq.offerLast(num);
        //     res[left] = dq.peekFirst();
        //     right++; left++;
        // }
        // return res;
    }
}