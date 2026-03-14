class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        adjList = defaultdict(list)
        for edge in edges:
            adjList[edge[0]].append(edge[1])
            adjList[edge[1]].append(edge[0])

        visited = set()

        def dfs(node, parent, count):
            visited.add(node)
            for child in adjList[node]:
                if child not in visited:
                    count = 1 + dfs(child, parent, count)
            return count

        pairs = 0
        for node in range(n):
            if node not in visited:
                size = dfs(node, node, 1)
                n = n - size
                pairs = pairs + (n*size)
        
        return pairs