class Solution {
    public boolean isPalindrome(String s) {
        int n = s.length();
        if (n == 1) return true;
        int left = 0, right = n - 1;
        while (left <= right) {
            char chLeft = s.charAt(left);
            char chRight = s.charAt(right);
            if (!Character.isLetterOrDigit(chLeft)) {
                left++;
            } else if (!Character.isLetterOrDigit(chRight)) {
                right--;
            } else {
                if (Character.toLowerCase(chLeft) != Character.toLowerCase(chRight)){
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
}