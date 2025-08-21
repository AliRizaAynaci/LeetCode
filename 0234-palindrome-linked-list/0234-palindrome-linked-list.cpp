/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    // Time Comp -> O(n)
    // Space Comp -> O(1)
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (!head || head->next == nullptr) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* right = reverseList(slow);

        ListNode* left = head;
        bool ok = true;
        ListNode* r = right;
        while (r) {
            if (left->val != r->val) {
                ok = false;
                break;
            }
            left = left->next;
            r = r->next;
        }
        return ok;
    }
};