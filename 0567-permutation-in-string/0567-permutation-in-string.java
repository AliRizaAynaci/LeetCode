class Solution {
    public static boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length()) return false;
        HashMap<Character, Integer> window = new HashMap<>();
        HashMap<Character, Integer> target = new HashMap<>();
        char[] str1 = s1.toCharArray();
        char[] str2 = s2.toCharArray();
        for (int i = 0; i < str1.length; i++) {
            target.put(str1[i], target.getOrDefault(str1[i], 0)+1);
            window.put(str2[i], window.getOrDefault(str2[i], 0)+1);
        }
        // early return
        if (target.equals(window)) return true;
        for (int right = str1.length; right < str2.length; right++) {
            window.put(str2[right], window.getOrDefault(str2[right], 0)+1);
            window.put(str2[right - str1.length], window.get(str2[right - str1.length])-1);
            if (window.get(str2[right - str1.length]) == 0) window.remove(str2[right - str1.length]);
            if (target.equals(window)) return true;
        }
        return false;
    }
}