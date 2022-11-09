class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        charSet = set()
        
        a = 0
        b = 0
        MAX = 0
        while a < len(s):
            if s[a] not in charSet:
                charSet.add(s[a])
                a += 1
                MAX = max(MAX, len(charSet))
            else:
                charSet.remove(s[b])
                b += 1
            
        return MAX
                