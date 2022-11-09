class Solution:
    def calPoints(self, operations: List[str]) -> int:

        mystack = []
        for i in operations:
            if i == "C":
                mystack.pop()
            elif i == "D":
                mystack.append(mystack[-1] * 2)
            elif i == "+":
                mystack.append(mystack[-1] + mystack[-2])
            else:
                mystack.append(int(i))
        return sum(mystack)
