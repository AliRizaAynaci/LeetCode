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
    int dfs(TreeNode* node, int *max_value) {
        if (!node) return 0;
        int left = max(dfs(node->left, max_value), 0);
        int right = max(dfs(node->right, max_value), 0);
        *max_value = max(*max_value, left + right + node->val);
        return max(left, right) + node->val;
    }

    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int max_value = INT_MIN;
        dfs(root, &max_value);
        return max_value;
    }
};