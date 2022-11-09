class Solution:
    def runningSum(self, nums):
        top = 0
        list=[]
        for i in nums:
            top+=i
            list.append(top)
        return(list)