# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:

        curr = headA
        dummy = headB

        while curr != dummy:
            curr = curr.next if curr != None else headB
            dummy = dummy.next if dummy != None else headA
        
        return curr