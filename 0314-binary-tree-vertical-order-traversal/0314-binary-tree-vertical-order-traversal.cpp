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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        unordered_map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int minColumn = 0, maxColumn = 0;
        while (!q.empty()) {
            auto [node, column] = q.front(); q.pop();
            mp[column].push_back(node->val);
            minColumn = min(minColumn, column);
            maxColumn = max(maxColumn, column);
            if (node->left) q.push({node->left, column - 1});
            if (node->right) q.push({node->right, column + 1});
        }
        for (int i = minColumn; i <= maxColumn; i++) {
            res.push_back(mp[i]);
        }
        return res;
    }
};