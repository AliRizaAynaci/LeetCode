class Solution {
    public boolean canConstruct(String s, int k) {
        if(s.length() < k)
            return false;
        int[] charCount = new int['z' - 'a' + 1];
        int odd = 0;
        for(char c : s.toCharArray())charCount['z' - c]++;
        for(int cC: charCount){
            if(cC > 0)
                odd += cC % 2;
        }
        return odd <= k ? true : false;
    }
}