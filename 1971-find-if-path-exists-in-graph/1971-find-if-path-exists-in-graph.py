class Solution:
    def dfs(self, adj, visited, source, destination):
        if source == destination:
            return True
            
        if visited[source]:
            return
        visited[source] = True

        for node in adj[source]:
            if self.dfs(adj, visited, node, destination):
                return True
        return False

    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        adj = defaultdict(list)
        for edge in edges:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])
        
        visited = [False for _ in range(n)]

        return self.dfs(adj, visited, source, destination)