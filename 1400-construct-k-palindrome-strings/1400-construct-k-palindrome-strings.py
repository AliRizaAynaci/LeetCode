class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        
        if len(s) < k:
            return False
        
        hashmap = {}
        
        for x in s:
            if x not in hashmap:
                hashmap[x] = 1
            else:
                hashmap[x] += 1
        odd = 0
        for key, values in hashmap.items():
            if values %2 != 0:
                odd += 1
        if odd <= k:
            return True
        else: return False
            
        