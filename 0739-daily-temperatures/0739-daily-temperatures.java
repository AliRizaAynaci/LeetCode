class Solution {
    public int[] dailyTemperatures(int[] temps) {
        int n = temps.length;
        int[] res = new int[n];
        if (n == 0) return res;
        Stack<Integer> st = new Stack<>();
        st.push(0);
        for (int i = 1; i < n; i++) {
            int now = temps[i];
            while (!st.isEmpty() && temps[st.peek()] < now) {
                int prev = st.pop();
                res[prev] = i - prev;
            }
            st.push(i);
        }
        return res;
    }
}