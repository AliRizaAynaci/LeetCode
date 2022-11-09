class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        
        nums.sort()
        res = sum(nums[:3])
        
        for i in range(len(nums) - 2):
            l = i + 1
            r = len(nums) - 1
            
            while l < r:
                sumhere = nums[i] + nums[l] + nums[r]
                if abs(sumhere - target) < abs(res - target):
                    res = sumhere
                if sumhere < target:
                    l += 1
                else:
                    r -= 1
        return res