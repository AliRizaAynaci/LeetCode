class Solution(object):
    def containsDuplicate(self, nums):
        
        hashmap = {}
        
        for index, num in enumerate(nums):
            if num not in hashmap:
                hashmap[num] = index
            else:
                return True
            
        return False