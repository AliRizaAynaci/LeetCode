class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        
        for i in range(26):
            curr_char = chr(ord('a') + i)
            
            if sentence.find(curr_char) == -1:
                return False
            
        return True