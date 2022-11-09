class Solution:
    def reverse(self, x: int) -> int:
        
        isnegative = x < 0
        MİN = -(pow(2,31))
        MAX = (pow(2,31))
        if x < 0:
            x = -x
        
        reverse = 0
        
        while x > 0:
            
            reverse = (reverse * 10) + x%10
            x = x // 10
            
        if reverse > MAX or reverse < MİN:
            return 0
        
        if isnegative:
            reverse = -reverse
        return reverse
            