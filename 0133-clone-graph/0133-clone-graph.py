"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return node

        visited = {}
        visited[node] = Node(node.val)
        
        q = [node]
        while len(q):
            currNode = q.pop(0)
            for n in currNode.neighbors:
                if n not in visited:
                    visited[n] = Node(n.val)
                    q.append(n)
                visited[currNode].neighbors.append(visited[n])
        return visited[node]
        