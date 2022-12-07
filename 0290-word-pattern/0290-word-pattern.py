class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        
        li = s.split(" ")
        hashmap = {}
        
        if len(li) != len(pattern):
            return False
        
        for i, val in enumerate(pattern):
            
            if val in hashmap and hashmap[val] != li[i]:
                return False
            
            elif val not in hashmap and li[i] in hashmap.values():
                return False
            
            elif val not in hashmap:
                hashmap[val] = li[i]
                
        return True