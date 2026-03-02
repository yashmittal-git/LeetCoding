# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        parent = {}
        def store_parent(root):
            if root.left:
                parent[root.left] = root
                store_parent(root.left)
            if root.right:
                parent[root.right] = root
                store_parent(root.right)
        store_parent(root)

        
        def bfs(target, k):
            q = [target]
            visited = set()
            
            while q:
                if k == 0:
                    return q
                nq = []
                for node in q:
                    visited.add(node)
                    if node.left and node.left not in visited:
                        nq.append(node.left)
                    if node.right and node.right not in visited:
                        nq.append(node.right)
                    if node in parent and parent[node] not in visited:
                        nq.append(parent[node])
                q = nq
                k = k-1
            
            return []
        
        nodes = bfs(target, k)
        result = []
        for node in nodes:
            result.append(node.val)
        return result
        