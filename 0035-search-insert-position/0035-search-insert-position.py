class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
            
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            
            if target == nums[mid]:
                return mid
            if target > nums[mid]:
                l += 1
            else:
                r -= 1
                
        return l