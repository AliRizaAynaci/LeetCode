class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        int n = strs.length;
        if (n == 0) return new ArrayList<>();
        HashMap<String, List<String>> anagrams = new HashMap<>();
        for (String str : strs) {
            char[] arr = str.toCharArray();
            Arrays.sort(arr);
            String key = new String(arr);
            if (!anagrams.containsKey(key)) {
                anagrams.put(key, new ArrayList<>());
            }
            anagrams.get(key).add(str);
        }
        return new ArrayList<>(anagrams.values());
    }
}