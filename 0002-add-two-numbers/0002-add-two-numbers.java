# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        pointer = ListNode(-1)
        temp = pointer
        overflow = 0
        
        while l1 or l2 or overflow:
            #process
            total = (l1.val if l1 else 0) + (l2.val if l2 else 0) + overflow
            temp.next = ListNode(total % 10)
            overflow = total // 10
            #update
            if l1: l1 = l1.next
            if l2: l2 = l2.next
            temp = temp.next
        
        return pointer.next