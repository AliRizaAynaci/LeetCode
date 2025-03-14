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
private:
    void dfs(TreeNode* node, TreeNode* parent, int length, int& maxLength) {
        if (node == nullptr) return;
        length = (parent != nullptr && node->val == parent->val + 1) ? length + 1 : 1;
        maxLength = max(maxLength, length);
        dfs(node->left, node, length, maxLength);
        dfs(node->right, node, length, maxLength);
    }

public:
    int longestConsecutive(TreeNode* root) {
        int maxLength = 0;
        dfs(root, nullptr, 0, maxLength);    
        return maxLength;
    }
};