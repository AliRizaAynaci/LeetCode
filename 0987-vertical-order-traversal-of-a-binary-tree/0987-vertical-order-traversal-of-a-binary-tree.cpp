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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int minIndex = 0, maxIndex = 0;

        while (!q.empty()) {
            int size = q.size();
            map<int, vector<int>> levelMap;
            
            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front(); q.pop();
                minIndex = min(minIndex, index);
                maxIndex = max(maxIndex, index);
                
                levelMap[index].push_back(node->val);
                
                if (node->left) q.push({node->left, index - 1});
                if (node->right) q.push({node->right, index + 1});
            }
            
            for (auto& [index, values] : levelMap) {
                sort(values.begin(), values.end());
                mp[index].insert(mp[index].end(), values.begin(), values.end());
            }
        }

        for (int i = minIndex; i <= maxIndex; i++) {
            result.push_back(mp[i]);
        }
        
        return result;
    }
};