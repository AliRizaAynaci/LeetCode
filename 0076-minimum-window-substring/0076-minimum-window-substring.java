class Solution {
    public static String minWindow(String s, String t) {
        if (s.length() < t.length()) return "";
        HashMap<Character, Integer> sMap = new HashMap<>();
        HashMap<Character, Integer> tMap = new HashMap<>();
        for (Character ch : t.toCharArray()) {
            tMap.put(ch, tMap.getOrDefault(ch, 0) + 1);
        }
        char[] sChars = s.toCharArray();
        int minLeft = 0, minLen = Integer.MAX_VALUE;
        int required = tMap.size(), have = 0;
        int left = 0;
        for (int right = 0; right < sChars.length; right++) {
            char ch = sChars[right];
            sMap.put(ch, sMap.getOrDefault(ch, 0) + 1);
            if (tMap.containsKey(ch) && sMap.get(ch).equals(tMap.get(ch))) {
                have++;
            }
            while (have == required) {
                char leftChar = sChars[left];
                sMap.put(leftChar, sMap.get(leftChar)-1);
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }
                if (tMap.containsKey(leftChar) && sMap.get(leftChar) < tMap.get(leftChar)) {
                    have--;
                }
                left++;
            }
        }
        return minLen == Integer.MAX_VALUE ? "" : s.substring(minLeft, minLeft + minLen);
    }
}