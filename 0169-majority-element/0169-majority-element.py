class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        
        result = 0 
        count = 0
        
        for num in nums:
            if count == 0:
                result = num
            if num == result:
                count += 1
            else:
                count -= 1
        return result