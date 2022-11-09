class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        if len(nums) <= 3: return []
        nums = sorted(nums)
        res = []
        n = len(nums)

        for i in range(0, n-3):
            for j in range(i+1, n-2):
                curMax = nums[i] + nums[j] + nums[-2] + nums[-1]
                curMin = nums[i] + nums[j] + nums[j+1] + nums[j+2]
                if not curMin <= target <= curMax: continue
                    
                l, r = j + 1, n - 1
                while l < r:
                    curSum = nums[i] + nums[j] + nums[l] + nums[r]
                    if curSum < target:
                        l += 1
                    elif curSum > target:
                        r -= 1
                    else:
                        if not [nums[i],nums[j],nums[l],nums[r]] in res:
                            res.append([nums[i],nums[j],nums[l],nums[r]])
                        l += 1
                        r -= 1
        return res