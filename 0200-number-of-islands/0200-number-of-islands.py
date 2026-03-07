class Solution:
    n = 0
    m = 0

    paths = [(-1,0),(1,0),(0,-1),(0,1)]

    def dfs(self, grid, i, j):
        if i < 0 or i >= self.n or j < 0 or j >=self.m or grid[i][j]=="0":
            return
        grid[i][j] = "0"
        for path in self.paths:
            self.dfs(grid,i+path[0],j+path[1])


    def numIslands(self, grid: List[List[str]]) -> int:
        self.n = len(grid)
        self.m = len(grid[0])
        answer = 0

        for i in range(self.n):
            for j in range(self.m):
                if grid[i][j]=="1":
                    answer = answer + 1
                    self.dfs(grid,i,j)
        
        return answer