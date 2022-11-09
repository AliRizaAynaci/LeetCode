class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        
        result = 0
        
        for number in nums:
            result = number ^ result
        return result