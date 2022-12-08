# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        
        newlist = []
        dummy = curr = ListNode(0)
        for i in lists:
            while i:
                newlist.append(i.val)
                i = i.next
        for x in sorted(newlist):
            curr.next = ListNode(x)
            curr = curr.next
        return dummy.next
                
                