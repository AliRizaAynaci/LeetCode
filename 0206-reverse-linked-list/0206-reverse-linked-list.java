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
    public static ListNode reverseList(ListNode head) {
        if (head == null) return null;
        ListNode prev = null;
        ListNode n = head.next;
        while (n != null) {
            head.next = prev;
            prev = head;
            head = n;
            n = n.next;
        }
        head.next = prev;
        prev = head;
        return prev;
    }
}