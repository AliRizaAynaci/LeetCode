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
       return dfs(root, head);
    }
    // ** DFS + DFS **
    bool dfs(TreeNode* root, ListNode* head) {
        if (root == nullptr) return false;
        if (matches(root, head)) return true;
        return dfs(root->left, head) || dfs(root->right, head);
    }

    bool matches(TreeNode* root, ListNode* head) {
        if (head == nullptr) return true;
        if (root == nullptr || root->val != head->val) return false;
        // head->val == root->val
        return matches(root->left, head->next) || matches(root->right, head->next);
    } 


    // ** DFS + BFS **
    // bool dfs(TreeNode* root, ListNode* head) {
    //     if (root == nullptr) return false;
    //     if (root->val == head->val && bfs(root, head)) return true;
    //     return dfs(root->left, head) || dfs(root->right, head);
    // }

    // bool bfs(TreeNode* root, ListNode* head) {
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     ListNode* curr = head->next;
    //     while (!q.empty() && curr != nullptr) {
    //         int size = q.size();
    //         for (int i = 0; i < size; i++) {
    //             TreeNode* node = q.front(); q.pop();
    //             if (node->left && node->left->val == curr->val) q.push(node->left);
    //             if (node->right && node->right->val == curr->val) q.push(node->right);
    //         }
    //         if (!q.empty()) curr = curr->next;
    //     }
    //     return curr == nullptr;
    // }
};