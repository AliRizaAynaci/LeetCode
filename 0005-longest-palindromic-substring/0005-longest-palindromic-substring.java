class Solution {
    public String longestPalindrome(String s) {
        
        if (s == null || s.length() < 1) return "";
        int left = 0;
        int right = 0;
        //int maxSubPalin = 0;
        String result = "";
        for(int i = 0;i< s.length();i++){

            // for Odd length of string
            left = i;
            right = i;
            while(left >=0 && right <s.length()){
                if(s.charAt(left) != s.charAt(right))
                break;

                if(s.charAt(left) == s.charAt(right))
                {
                   if(result.length()< right-left+1){
                     result = s.substring(left,right+1);
                   }
                }
                left--;
                right++;
            }

            // for Even length of string 
            left = i;
            right = i+1;   

            while(left >=0 && right <s.length()){
                if(s.charAt(left) != s.charAt(right))
                break;

                if(s.charAt(left) == s.charAt(right))
                {
                   if(result.length()< right-left+1){
                     result = s.substring(left,right+1);
                   }
                }
                left--;
                right++;
            }    
        }
        return result;
    }
}