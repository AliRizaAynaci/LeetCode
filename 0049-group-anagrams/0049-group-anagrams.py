class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        h = {}
        
        for word in strs:
            
            sortedword = "".join(sorted(word))
            if sortedword not in h:
                h[sortedword] = [word]
            else:
                h[sortedword].append(word)
        final = []
        for value in h.values():
            final.append(value)
        return final