class Solution {
    public static boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        int[] arr = new int[26];
        for (int i = 0; i < s.length(); i++) {
            arr[s.charAt(i) - 'a']++;
            arr[t.charAt(i) - 'a']--;
        }

        for (int val : arr) {
            if (val != 0) return false;
        }
        return true;
//        if (s.length() != t.length()) return false;
//        HashMap<Character, Integer> map = new HashMap<>();
//        for (int i = 0; i < s.length(); i++) {
//            char ch = s.charAt(i);
//            map.put(ch, map.getOrDefault(ch, 0) + 1);
//        }
//        for (int i = 0; i < t.length(); i++) {
//            char ch = t.charAt(i);
//            if (!map.containsKey(ch)) {
//                return false;
//            }
//            map.put(ch, map.get(ch)-1);
//            if (map.get(ch) == 0) map.remove(ch);
//        }
//
//        return true;
    }
}