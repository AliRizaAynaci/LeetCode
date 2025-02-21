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
    int postorder(TreeNode* node, int& maxVal) {
        if (node == nullptr) return 0;
        int left = max(postorder(node->left, maxVal), 0);
        int right = max(postorder(node->right, maxVal), 0);
        maxVal = max(maxVal, left + right + node->val);
        return max(left, right) + node->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxVal = INT_MIN;
        postorder(root, maxVal);
        return maxVal;
    }
};