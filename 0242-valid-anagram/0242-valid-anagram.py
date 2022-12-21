class Solution:
    def isAnagram(self, s1: str, s2: str) -> bool:
        
        s1 = s1.replace(' ','').lower()
        s2 = s2.replace(' ','').lower()

        #Edge Case Check
        if len(s1) != len(s2):
            return False

        count = {}

        for letter in s1:
            if letter in count:
                count[letter] += 1
            else:
                count[letter] = 1

        for letter in s2:
            if letter in count:
                count[letter] -= 1
            else:
                count[letter] = 1

        for k in count:
            if count[k] != 0:
                 return False
    
        return True