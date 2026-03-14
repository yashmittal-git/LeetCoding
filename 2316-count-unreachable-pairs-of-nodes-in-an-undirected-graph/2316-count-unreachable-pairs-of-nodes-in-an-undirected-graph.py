class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        adjList = defaultdict(list)
        for edge in edges:
            adjList[edge[0]].append(edge[1])
            adjList[edge[1]].append(edge[0])

        visited = set()

        components = defaultdict(list)

        def dfs(node, parent):
            visited.add(node)
            for child in adjList[node]:
                if child not in visited:
                    components[parent].append(child)
                    dfs(child, parent)

        for node in range(n):
            if node not in visited:
                dfs(node, node)
                if node not in components:
                    components[node] = []
        sizes = []
        for key, val in components.items():
            sizes.append(1+len(val))
        
        pairs = 0
        for size in sizes:
            n = n - size
            pairs = pairs + (n*size)
        return pairs