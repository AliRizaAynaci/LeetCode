class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        
        count = collections.Counter()
        count2 = collections.Counter()
        
        total = 0
        for i in nums:
            total += count2[i - diff]
            count2[i] += count[i - diff]
            count[i] +=1
            
        return total
            