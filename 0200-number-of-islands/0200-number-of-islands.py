class Solution:

    paths = [(-1,0),(1,0),(0,1),(0,-1)]
    m = 0
    n = 0

    def bfs(self, grid, i, j):
        q = [(i,j)]

        while len(q):
            i1, j1 = q.pop()
            
            for path in self.paths:
                i2 = i1 + path[0]
                j2 = j1 + path[1]

                if i2 >= 0 and i2 < self.m and j2 >=0 and j2 < self.n and grid[i2][j2] == "1":
                    grid[i2][j2] = "0"
                    q.append((i2,j2))

    def numIslands(self, grid: List[List[str]]) -> int:
        self.m = len(grid)
        self.n = len(grid[0])
        answer = 0

        for i in range(self.m):
            for j in range(self.n):
                if grid[i][j] == "1":
                    answer = answer + 1
                    grid[i][j] = "0"
                    self.bfs(grid, i, j)
        
        return answer