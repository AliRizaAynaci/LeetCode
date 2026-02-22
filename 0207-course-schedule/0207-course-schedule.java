class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        
        int n = prerequisites.length;
        if (n == 0) return true;
        int[] indegrees = new int[numCourses];
        for (int[] courses : prerequisites) {
            int i = courses[0];
            indegrees[i]++;
        }
        HashMap<Integer, List<Integer>> adjList = new HashMap<>();
        for (int[] courses : prerequisites) {
            if (!adjList.containsKey(courses[1])) {
                adjList.put(courses[1], new ArrayList<>());
            }
            adjList.get(courses[1]).add(courses[0]);
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                q.offer(i);
            }
        }
        int takenCount = 0;
        while (!q.isEmpty()) {
            int course = q.poll();
            takenCount++;
            List<Integer> neighbours = adjList.getOrDefault(course, new ArrayList<>());
            for (int v : neighbours) {
                indegrees[v]--;
                if (indegrees[v] == 0) {
                    q.offer(v);
                }
            }
        }
        return takenCount == numCourses;

        // int n = prerequisites.length;
        // if (n == 0) return true;
        // int[] indegrees = new int[numCourses];
        // for (int[] courses : prerequisites) {
        //     int i = courses[0];
        //     indegrees[i]++;
        // }
        // List<List<Integer>> adjList = new ArrayList<>();
        // for (int i = 0; i < numCourses; i++) {
        //     adjList.add(new ArrayList<>());
        // }
        // for (int[] courses : prerequisites) {
        //     adjList.get(courses[1]).add(courses[0]);
        // }
        // Queue<Integer> q = new LinkedList<>();
        // for (int i = 0; i < numCourses; i++) {
        //     if (indegrees[i] == 0) {
        //         q.offer(i);
        //     }
        // }
        // int takenCount = 0;
        // while (!q.isEmpty()) {
        //     int course = q.poll();
        //     takenCount++;
        //     for (int v : adjList.get(course)) {
        //         indegrees[v]--;
        //         if (indegrees[v] == 0) {
        //             q.offer(v);
        //         }
        //     }
        // }
        // return takenCount == numCourses;
    }
}