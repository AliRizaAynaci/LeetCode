class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] indegrees = new int[numCourses];
        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int[] pre : prerequisites) {
            indegrees[pre[0]]++;
            adjList.get(pre[1]).add(pre[0]);
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                q.offer(i);
            }
        }
        int[] res = new int[numCourses];
        int idx = 0;
        while (!q.isEmpty()) {
            int course = q.poll();
            res[idx++] = course;
            for (int v : adjList.get(course)) {
                indegrees[v]--;
                if (indegrees[v] == 0) {
                    q.offer(v);
                }
            }
        }
        return idx == numCourses ? res : new int[]{};
    }
}