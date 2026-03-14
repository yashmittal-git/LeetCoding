class UnionFind:
    def __init__(self, size):
        self.size = size
        self.parent = [_ for _ in range(size)]
        self.rank = [0 for _ in range(size)]
    
    def find(self, node):
        if self.parent[node] == node:
            return node
        self.parent[node] = self.find(self.parent[node])
        return self.parent[node]
    
    def union(self, node1, node2):
        node1_parent = self.find(node1)
        node2_parent = self.find(node2)
        if node1_parent == node2_parent:
            return
        
        if self.rank[node1_parent] > self.rank[node2_parent]:
            self.parent[node2_parent] = node1_parent
            self.rank[node1_parent] = self.rank[node1_parent] + 1
        else:
            self.parent[node1_parent] = node2_parent
            self.rank[node2_parent] = self.rank[node2_parent] + 1

class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        uf = UnionFind(n)
        components = defaultdict(int)
        for edge in edges:
            uf.union(edge[0],edge[1])
        
        for node in range(n):
            parent = uf.find(node)
            components[parent] = components[parent] + 1
        
        pairs = 0
        for component, size in components.items():
            n = n - size
            pairs = pairs + size*n
        
        return pairs
        
        