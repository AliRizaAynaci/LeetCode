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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> res;
        stack<TreeNode*> node;
        
        while(!node.empty() or root){
            
            if(root){
                res.push_back(root -> val);
                
                if(root -> right){
                    node.push(root -> right);
                }
                root = root -> left;
            }
            else{
                root = node.top();
                node.pop();
            }
        }
        return res;
    }
};