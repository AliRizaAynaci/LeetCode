class Solution:
    def removeDuplicates(self, s: str) -> str:
        
        myStack = []
        
        for i in s:
            if myStack and myStack[-1] == i:
                myStack.pop()
                
            else:
                myStack.append(i)
        
        return ''.join(myStack)
        