# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    maxDepth = 0

    def depth(self,root):
        if not root:
            return 0
        leftDepth = self.depth(root.left)
        rightDepth = self.depth(root.right)

        self.maxDepth = max(self.maxDepth, leftDepth+rightDepth)
        
        return max(leftDepth, rightDepth) + 1

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.depth(root)
        return self.maxDepth