class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) return 0;
        char[] str = s.toCharArray();
        HashMap<Character, Integer> map = new HashMap<>();
        int left = 0, longest = 0;
        for (int right = 0; right < str.length; right++) {
            char ch = str[right];
            if (map.containsKey(ch)) {
                left = Math.max(left, map.get(ch)+1);
            }
            longest = Math.max(longest, right - left + 1);
            map.put(ch, right);
        }
        return longest;
    }
}