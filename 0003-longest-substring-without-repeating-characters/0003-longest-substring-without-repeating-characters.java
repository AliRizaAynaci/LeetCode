class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) return 0;
        HashMap<Character, Integer> lastSeen = new HashMap<>();
        int l = 0, longest = 0;
        for (int r = 0; r < s.length(); r++) {
            char ch = s.charAt(r);
            if (lastSeen.containsKey(ch)) {
                l = Math.max(l, lastSeen.get(ch)+1);
            }
            lastSeen.put(ch, r);
            longest = Math.max(longest, (r-l+1));
        }
        return longest;
    }
}