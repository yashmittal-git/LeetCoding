# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root == None or p.val == root.val or q.val == root.val or (p.val < root.val and q.val > root.val ) or (p.val > root.val and q.val < root.val):
            return root
        traverseLeft = self.lowestCommonAncestor(root.left,p,q)
        if traverseLeft != None:
            return traverseLeft
        traverseRight = self.lowestCommonAncestor(root.right,p,q)
        if traverseRight != None:
            return traverseRight
        
        return None