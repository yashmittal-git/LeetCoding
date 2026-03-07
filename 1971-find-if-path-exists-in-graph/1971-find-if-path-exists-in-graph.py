class Solution:

    def bfs(self, adj, visited, source, destination):
        q = [source]
        visited[source] = True

        while len(q):
            node = q.pop()

            for child in adj[node]:
                if not visited[child]:
                    if child == destination:
                        return True
                    visited[child] = True
                    q.append(child)
        
        return False

    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        if source == destination:
            return True

        adj = defaultdict(list)

        for edge in edges:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])
        
        visited = [False for _ in range(n)]

        return self.bfs(adj, visited, source, destination)