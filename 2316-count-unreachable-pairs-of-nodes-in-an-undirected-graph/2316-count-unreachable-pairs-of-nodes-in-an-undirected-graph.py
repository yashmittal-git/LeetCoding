class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:

        adjList = defaultdict(list)

        for edge in edges:
            adjList[edge[0]].append(edge[1])
            adjList[edge[1]].append(edge[0])
        
        visited = set()

        def bfs(node):
            count = 0
            q = [node]
            visited.add(node)
            while q:
                node = q.pop()
                count = count + 1

                for child in adjList[node]:
                    if child not in visited:
                        visited.add(child)
                        q.append(child)
            
            return count

        pairs = 0
        for i in range(n):
            if i not in visited:
                count = bfs(i)
                n = n - count
                pairs = pairs + n*count
        
        return pairs