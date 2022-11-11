import heapq

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        
        minHeap = []
        
        for i, j in points:
            distanceToOrigin = (i ** 2) + (j ** 2)
            minHeap.append([distanceToOrigin, i, j])
            
        heapq.heapify(minHeap)
        result = []
        
        while k > 0:
            distance, i, j = heapq.heappop(minHeap)
            result.append([i, j])
            k -= 1
            
        return result