# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def depth(self,root,currDepth) -> int:
        if not root:
            return currDepth
        
        currDepth = currDepth + 1

        return max(self.depth(root.left,currDepth), self.depth(root.right, currDepth))
        

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.depth(root,0)
        