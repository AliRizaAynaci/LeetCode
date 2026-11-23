class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        Arrays.sort(piles);
        int n = piles.length;
        int left = 1, right = piles[n-1];
        while (left < right) {
            int k = left + (right - left) / 2;
            int count = 0;
            for (int pile : piles) {
                int hours = pile / k;
                if (pile % k != 0) hours++;
                count += hours;
            }
            if (count > h) {
                left = k + 1;
            } else {
                right = k;
            }
        }
        return left;
    }
}