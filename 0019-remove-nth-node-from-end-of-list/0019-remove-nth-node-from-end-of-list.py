# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        
        if head.next == None:
            return None 

        counter = 0
        dummy = curr = head
        
        while dummy:
            counter += 1
            dummy = dummy.next
            
        if counter - n == 0:
            return curr.next
            
        for i in range(counter - n - 1):
            curr = curr.next
        
        curr.next = curr.next.next
        return head
            