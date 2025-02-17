/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result;
        findLCA(root, p, q, result);
        return result;
    }

    bool findLCA(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode*& result) {
        if (node == nullptr) return false;
        bool left = findLCA(node->left, p, q, result);
        bool right = findLCA(node->right, p, q, result);
        bool curr = node == p || node == q;
        if ((left && right) || (left && curr) || (right && curr)) result = node;
        return left || right || curr;
    }
};