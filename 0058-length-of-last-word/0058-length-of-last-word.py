class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        
        if s[-1] == " ":
            s = s.strip()
        res = []
        for i in s[::-1]:
            if i == " ":
                break
            res.append(i)
        return len(res)