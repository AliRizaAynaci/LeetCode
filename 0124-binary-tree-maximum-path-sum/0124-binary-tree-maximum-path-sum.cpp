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
    int solution(TreeNode* root, int &mx){
        
        if(root == NULL) return 0;
        
        int left = max(0, solution(root -> left, mx));
        int right = max(0, solution(root -> right, mx));
        int currVal = root -> val;
        
        mx = max(mx, left + right + currVal);
        
        return max(left, right) + currVal;
    }
    int maxPathSum(TreeNode* root) {
        
        int mx = INT_MIN;
        solution(root, mx);
        return mx;
        
        
    }
};