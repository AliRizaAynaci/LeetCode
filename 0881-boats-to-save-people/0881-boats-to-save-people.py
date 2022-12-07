class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        
        people.sort()
        boats = 0
        
        leftpointer = 0
        rightpointer = len(people) - 1
        
        while leftpointer <= rightpointer:
            
            spaceLeft = limit - people[rightpointer]
            rightpointer -= 1
            boats += 1
            
            if spaceLeft >= people[leftpointer]:
                leftpointer += 1
                
        return boats
    