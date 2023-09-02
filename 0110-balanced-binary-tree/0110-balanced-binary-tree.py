# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def height(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        if root.left == None and root.right == None:
            return 1
        return max(self.height(root.left), self.height(root.right)) + 1
    
    
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if root == None:
            return True

        if abs(self.height(root.left) - self.height(root.right)) > 1:
            return False
            
        return self.isBalanced(root.right) and self.isBalanced(root.left)