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
    public ListNode reverseList(ListNode head) {
        if (head == null) return null;
        ListNode prev = null;
        ListNode curr = head;
        ListNode nx = curr.next;
        while (nx != null) {
            curr.next = prev;
            prev = curr;
            curr = nx;
            nx = nx.next;
        }
        curr.next = prev;
        prev = curr;
        return prev;
    }
}