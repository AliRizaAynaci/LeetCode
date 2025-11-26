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
    // Time Comp : O(N)
    // Every node is visited once so time comp is O(N)
    
    // Space Comp : O(N)
    // The maximum space for the queue is limited by the maximum width (w) of the tree,
    //      which is N/2 in the worst case (a complete tree), leading to O(N) space
    // max space for res array is limited by max depth (h), the worst case is 
    //     an unbalanced tree the h equals to N
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root); 
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currNode = q.front(); q.pop();
                if (i == levelSize - 1) {
                    res.push_back(currNode->val);
                }
                if (currNode->left) q.push(currNode->left);
                if (currNode->right) q.push(currNode->right);
            }
        }
        return res;
    }
};