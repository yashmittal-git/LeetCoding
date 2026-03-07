class UnionFind:
    def __init__(self, n):
        self.n = n
        self.rank = [0 for _ in range(n)]
        self.parent = [i for i in range(n)]
        
    def find(self, node):
        if self.parent[node] == node:
            return node
        self.parent[node] = self.find(self.parent[node])
        return self.parent[node]        
    
    def union(self, node1, node2):
        node1_parent = self.find(node1)
        node2_parent = self.find(node2)
        if node1_parent != node2_parent:
            if self.rank[node1_parent] > self.rank[node2_parent]:
                self.parent[node2_parent] = node1_parent
                self.rank[node1_parent] = self.rank[node1_parent] + 1
            else:
                self.parent[node1_parent] = node2_parent
                self.rank[node2_parent] = self.rank[node2_parent] + 1


class Solution:

    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        uf = UnionFind(n)
        for edge in edges:
            uf.union(edge[0], edge[1])
        
        return uf.find(source) == uf.find(destination)
        