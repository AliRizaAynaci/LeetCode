class Solution {
    public static int lengthOfLongestSubstring(String s) {
        int n = s.length();
        if (n <= 1) return n;
        int left = 0, maxLength = 0;
        // HashMap<Character, Integer> seen = new HashMap<>();
        int[] seen = new int[128];
        Arrays.fill(seen, -1);
        for (int right = 0; right < n; right++) {
            char ch = s.charAt(right);
            if (seen[ch] >= left) {
                left = seen[ch]+1;
            }
            seen[ch] = right;
//            if (seen.containsKey(ch)) {
//                left = Math.max(left, seen.get(ch)+1);
//                seen.remove(ch);
//            }
//            seen.put(ch, right);
            maxLength = Math.max(maxLength, (right - left + 1));
        }
        return maxLength;
    }
}