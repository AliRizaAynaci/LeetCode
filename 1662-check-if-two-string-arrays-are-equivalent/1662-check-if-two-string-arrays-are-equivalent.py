class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        #i, j = 0, 0
        #newstr1 = ""
        #newstr2 = ""
        #while i < len(word1):
        #    newstr1 += word1[i]
        #    i += 1
        
        #while j < len(word2):
        #   newstr2 += word2[j]
        #    j += 1
            
        #if newstr1 == newstr2:
        #    return True
        #else:
        #   return False
        
        str1 = "".join(word1)
        str2 = "".join(word2)
        if str1 == str2:
            return True
        else:
            return False
            
            
        
       