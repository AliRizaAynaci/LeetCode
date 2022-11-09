class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        #floydSolution

        fastpointer = 0
        slowpointer = 0

        while True:
            slowpointer = nums[slowpointer]
            fastpointer = nums[nums[fastpointer]]
            if slowpointer == fastpointer:
                break
        
        secondslowpointer = 0

        while True:
            slowpointer = nums[slowpointer]
            secondslowpointer = nums[secondslowpointer]
            if slowpointer == secondslowpointer:
                return slowpointer