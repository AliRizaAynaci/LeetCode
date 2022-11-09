# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        sum = 0

        def solution(node):

            nonlocal sum
            if node:
                solution(node.right)
                node.val += sum
                sum = node.val
                solution(node.left)
            return node
        
        return solution(root)