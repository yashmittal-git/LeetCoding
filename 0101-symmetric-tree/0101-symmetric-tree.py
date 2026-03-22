# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkSymmetry(self, node1, node2):
        if not node1 and not node2:
            return True
        if not node1 or not node2:
            return False
        if node1.val != node2.val:
            return False
        if self.checkSymmetry(node1.left, node2.right) and self.checkSymmetry(node1.right,node2.left):
            return True
        return False
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.checkSymmetry(root.left, root.right)
        