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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, root);
    }

    bool dfs(ListNode* llist, TreeNode* node) {
        if (node == nullptr) return false;
        if (llist->val == node->val && bfs(llist, node)) return true;
        return dfs(llist, node->left) || dfs(llist, node->right);
    }

    bool bfs(ListNode* llist, TreeNode* node) {
        queue<TreeNode*> q;
        q.push(node);
        ListNode* dummy = llist->next;
        while (!q.empty() && dummy != nullptr) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front(); q.pop();
                if (curr->left && curr->left->val == dummy->val) q.push(curr->left);
                if (curr->right && curr->right->val == dummy->val) q.push(curr->right);
            }
            if (!q.empty()) dummy = dummy->next;
        }
        return dummy == nullptr;
    }

    // bool dfs(ListNode* llist, TreeNode* node) {
    //     if (node == nullptr) return false;
    //     if (llist == nullptr || matches(llist, node)) return true;
    //     return dfs(llist, node->left) || dfs(llist, node->right);
    // }

    // bool matches(ListNode* llist, TreeNode* node) {
    //     if (llist == nullptr) return true;
    //     if (node == nullptr || llist->val != node->val) return false;
    //     // we know llist->val = node->val after this line
    //     return matches(llist->next, node->left) || matches(llist->next, node->right);
    // }
};