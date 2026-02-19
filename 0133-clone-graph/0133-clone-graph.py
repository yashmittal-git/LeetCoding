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
        visited = {}

        def dfs(node):
            if not node:
                return None

            if node not in visited:
                newNode = Node(node.val)
                visited[node] = newNode 
                for n in node.neighbors:
                    newNode.neighbors.append(dfs(n))
            
            return visited[node]

        return dfs(node)
        