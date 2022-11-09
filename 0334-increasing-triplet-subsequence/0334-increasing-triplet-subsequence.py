class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        
        #x = 0
        #while x < len(nums) - 2:
        #    for y in range(x + 1, len(nums) - 1):
        #        for i in range(y + 1, len(nums)):
        #            if nums[x] < nums[y] < nums[i]:
        #                return True
        #    x += 1
        #return False
        
        
        num_i = num_j = float('inf')
        
        for num in nums:
            if num <= num_i:
                num_i = num
            elif num <= num_j:
                num_j = num
            else: 
                return True
        return False