class Solution {
    public int hammingWeight(int n) {
        // 7 = 0111
        // 1 = 0001
        // 7 & 1 = 0111 & 0001 = 0001
        // while n != 0 -> n = n >>> 1;
        int count = 0;
        while (n != 0) {
            count += n & 1;
            n = n >>> 1;
        }
        return count;
    }
}