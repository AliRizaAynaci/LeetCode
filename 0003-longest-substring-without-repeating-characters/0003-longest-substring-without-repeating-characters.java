class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) return 0;
        char[] str = s.toCharArray();
        // HashMap<Character, Integer> map = new HashMap<>();
        int[] seen = new int[128];
        Arrays.fill(seen, -1);
        int left = 0, longest = 0;
        for (int right = 0; right < str.length; right++) {
            char ch = str[right];
            if (seen[ch] != -1) {
                left = Math.max(left, seen[ch]+1);
            }
            longest = Math.max(longest, right - left + 1);
            seen[ch] = right;
        }
        return longest;
    }
}