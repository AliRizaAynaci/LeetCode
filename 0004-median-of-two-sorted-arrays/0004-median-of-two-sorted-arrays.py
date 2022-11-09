class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        list = nums1 + nums2
        total = 0.00
        median = 0.00
        list.sort()
            
        if len(list) %2 == 0:
            x = len(list)//2
            total = list[x] + list[x - 1]
            median = float(total/2)
            return median
        else:
            x = len(list)//2
            median = float(list[x])
            return median
