# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if head.next == None:
            return None
        
        counter = 0
        dummy = curr = head
        while dummy:
            counter += 1
            dummy = dummy.next
            
            
        mid = counter // 2
        for i in range(mid - 1):
            curr = curr.next
        
        curr.next= curr.next.next
        return head