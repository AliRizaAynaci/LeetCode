class Solution {
    public static int lengthOfLongestSubstring(String s) {
        int n = s.length();
        if (n <= 1) return n;
        int left = 0, maxLength = 0;
        HashMap<Character, Integer> seen = new HashMap<>();
        for (int right = 0; right < n; right++) {
            char ch = s.charAt(right);
            if (seen.containsKey(ch)) {
                left = Math.max(left, seen.get(ch)+1);
                seen.remove(ch);
            }
            seen.putIfAbsent(ch, right);
            maxLength = Math.max(maxLength, (right - left + 1));
        }
        return maxLength;
    }
}