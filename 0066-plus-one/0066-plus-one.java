class Solution {
    public int[] plusOne(int[] digits) {
        
        int i = digits.length - 1;
        
        while(i >= 0){
            if(digits[i] < 9){
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
            i --;
        }
        int [] new_number = new int[digits.length + 1];
        new_number[0] = 1;
        return new_number;
        
        
        
        
        
    }
}