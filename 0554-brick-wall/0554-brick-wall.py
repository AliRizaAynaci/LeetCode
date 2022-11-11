class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        
        hashmap = {0:0}
        
        for row in wall:
            gapIndex = 0
            for brick in row[:-1]:
                gapIndex += brick
                hashmap[gapIndex] = 1 + hashmap.get(gapIndex, 0)
        
        maxgapNumber = max(hashmap.values())
        return len(wall) - maxgapNumber