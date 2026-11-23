class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> resList = new ArrayList<>();
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        int s1 = intervals[0][0], e1 = intervals[0][1];
        for (int i = 1; i < intervals.length; i++) {
            int s2 = intervals[i][0];
            int e2 = intervals[i][1];
            if (s2 <= e1) {
                e1 = Math.max(e1, e2);
            } else {
                resList.add(new int[] {s1, e1});
                s1 = s2;
                e1 = e2;
            }
        }
        resList.add(new int[] {s1, e1});
        int[][] res = new int[resList.size()][2];
        for (int i = 0; i < resList.size(); i++) {
            res[i] = resList.get(i);
        }
        return res;
    }
}