class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) return 0;
        int l = 0;
        HashMap<Character, Integer> seen = new HashMap<>();
        int longest = 0;
        for (int r = 0; r < s.length(); r++) {
            char ch = s.charAt(r);
            if (seen.containsKey(ch)) {
                l = Math.max(l, seen.get(ch)+1);
            }
            longest = Math.max(longest, r-l+1);
            seen.put(ch, r);
        }
        return longest;
    }
    /**
            abcabcbb
    l = 0, 1 r = 0, 1, 2, 3
    window: (a,b,c) -> 
    [bu gecis asamasinda max window size kiyaslamasi yap] 
    [onceden gorulmusu degeri atlarken sola gitmemesi lazim
    bu yuzden seen[ch] > left yapmaliyim]
    [right ile ilerlerken windowa giren her yeni deger seen
    mapine eklenmeli indeksiyle beraber]
    window: (b,c,a)
    seen: {
        a : 0
        b : 1
        c : 2
    }
     */
}