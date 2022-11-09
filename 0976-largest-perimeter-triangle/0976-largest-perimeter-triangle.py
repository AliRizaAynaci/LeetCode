class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        
        nums = sorted(nums)[::-1]
        for a, b, c in zip(nums, nums[1:], nums[2:]):
            if a < b + c:
                return  a+b+c
        return 0
        