class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        
        result = [0] * len(temperatures)
        mystack = []

        for i, num in enumerate(temperatures):
            while mystack and num > mystack[-1][0]:
                stacknum, stackindex = mystack.pop()
                result[stackindex] = i - stackindex
            mystack.append([num, i])
        return result
        
        '''i = 0
        res = []

        while i < len(temperatures):
            counter = 0
            if i != len(temperatures) - 1:
                j = i + 1
                while j < len(temperatures):
                    if temperatures[j] > temperatures[i]:
                        counter = j - i
                        break
                    else:
                        j += 1
            res.append(counter)
            i += 1
        return res'''
        

