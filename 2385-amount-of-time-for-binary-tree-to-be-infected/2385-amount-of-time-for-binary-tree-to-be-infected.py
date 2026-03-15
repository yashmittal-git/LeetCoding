# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        parents = {}
        q = []
        def store_parent(root):
            if root.val == start:
                q.append(root)
            if root.left:
                parents[root.left] = root
                store_parent(root.left)
            if root.right:
                parents[root.right] = root
                store_parent(root.right)
        store_parent(root)

        visited = set()
        visited.add(q[0])

        time = -1
        while q:
            time = time + 1
            nq = []
            while q:
                node = q.pop()
                if node.right and node.right not in visited:
                    nq.append(node.right)
                    visited.add(node.right)
                if node.left and node.left not in visited:
                    nq.append(node.left)
                    visited.add(node.left)
                if node in parents and parents[node] not in visited:
                    nq.append(parents[node])
                    visited.add(parents[node])
            q = nq
                
        return time
                