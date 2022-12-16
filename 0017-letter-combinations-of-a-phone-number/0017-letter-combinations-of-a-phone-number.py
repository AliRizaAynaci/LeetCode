class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        '''Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.'''
        # no digit
        if not digits:
            return []
        key_map = {
            2 : ['a', 'b', 'c'],
            3 : ['d', 'e', 'f'],
            4 : ['g', 'h', 'i'],
            5 : ['j', 'k', 'l'],
            6 : ['m', 'n', 'o'],
            7 : ['p', 'q', 'r', 's'],
            8 : ['t', 'u', 'v'],
            9 : ['w', 'x', 'y', 'z']
        }
        ans = ['']
        for d in digits:
            new_ans = [x+y for x in ans for y in key_map[int(d)]]
            ans = new_ans
        return ans