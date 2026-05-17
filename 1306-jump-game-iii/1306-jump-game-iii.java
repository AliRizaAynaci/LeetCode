class Solution {
    public boolean canReach(int[] arr, int start) {
        int n = arr.length;
        Queue<Integer> q = new LinkedList<>();
        boolean[] seen = new boolean[n];
        q.offer(start);
        seen[start] = true;
        while (!q.isEmpty()) {
            int idx = q.poll();
            if (arr[idx] == 0) return true;
            int forward = idx + arr[idx];
            int backward = idx - arr[idx];
            if (forward < n && !seen[forward]) {
                seen[forward] = true;
                q.offer(forward);
            }
            if (backward >= 0 && !seen[backward]) {
                seen[backward] = true;
                q.offer(backward);
            }
        }
        return false;
    }
}