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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> arr1;
        vector<int> arr2;
        
        dfs(root1, arr1);
        dfs(root2, arr2);
        
        return arr1 == arr2;
    }
    void dfs(TreeNode* node, vector<int>& arr){
        if (node == NULL) return;
        if (node -> left == NULL && node -> right == NULL){
            arr.push_back(node -> val);
        }
        dfs(node -> left, arr);
        dfs(node ->right, arr);
    }
};