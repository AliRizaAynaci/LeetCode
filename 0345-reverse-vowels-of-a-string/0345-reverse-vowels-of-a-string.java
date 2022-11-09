class Solution:
    def reverseVowels(self, s: str) -> str:

        vowels = ["a", "A", "e", "E", "i",'I', "o", "O", "u", "U"] 
        reverse = list(s) 
        i, j = 0, len(s) - 1 
        while i < j: 
            if reverse[i] in vowels and reverse[j] in vowels: 
                reverse[i], reverse[j] = reverse[j], reverse[i] 
                i += 1
                j -= 1
            elif reverse[i] not in vowels: 
                i += 1 
            else: 
                j -= 1 
                
        return "".join(reverse)
 
