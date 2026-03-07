# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    count = 0

    def kSmallest(self, root, k):
        if not root:
            return None
        left = self.kSmallest(root.left, k)
        if left:
            return left
        self.count = self.count + 1
        if self.count == k:
            return root
        right = self.kSmallest(root.right, k)
        if right:
            return right

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        if not root:
            return
        return self.kSmallest(root, k).val
        