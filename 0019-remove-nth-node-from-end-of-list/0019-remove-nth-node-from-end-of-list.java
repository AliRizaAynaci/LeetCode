/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public static ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null) return null;
        ListNode ptr1 = head;
        ListNode ptr2 = head;
        for (int i = 0; i < n; i++) {
            ptr1 = ptr1.next;
        }
        if (ptr1 == null) return head.next;
        while (ptr1.next != null) {
            ptr1 = ptr1.next;
            ptr2 = ptr2.next;
        }
        ptr2.next = ptr2.next.next;
        return head;
    }
}