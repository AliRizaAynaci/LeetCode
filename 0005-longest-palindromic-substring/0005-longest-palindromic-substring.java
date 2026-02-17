class Solution {
    private int[] expand(char[] str, int mid) {
        int l = mid - 1, r = mid + 1;
        
        while (l > 0 && str[l] == str[mid]) l--;
        while (r < str.length && str[r] == str[mid]) r++;
        while (l >= 0 && r < str.length && str[l] == str[r]) {
            l--;
            r++;
        }
        return new int[] {l+1, r-1};
    }

    public String longestPalindrome(String s) {
        if (s.length() <= 1) return s;
        int longestLeft = 0, longestRight = 0;
        int longestPalindrome = Integer.MIN_VALUE;
        char[] str = s.toCharArray();
        for (int i = 0; i < str.length; i++) {
            int[] indexes = expand(str, i);
            int left = indexes[0];
            int right = indexes[1];
            int currLong = right - left + 1;
            if (currLong >= longestPalindrome) {
                longestPalindrome = currLong;
                longestLeft = left;
                longestRight = right;
            }
        }
        return s.substring(longestLeft, longestRight+1);
    }
}
