class Solution:
    m = 0
    n = 0

    def getArea(self, grid, i, j):
        if grid[i][j] == 0:
            return 0

        directions = [(-1,0),(0,1),(0,-1),(1,0)]

        currentArea = 1
        grid[i][j]=0

        for direction in directions:
            i1 = i + direction[0]
            j1 = j + direction[1]
            if i1 < 0 or i1 >=self.m or j1 < 0 or j1 >=self.n or grid[i1][j1] == 0:
                continue
            currentArea = currentArea + self.getArea(grid, i1, j1)
        return currentArea


    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.m = len(grid)
        self.n = len(grid[0])

        maxArea = 0

        for i in range(self.m):
            for j in range(self.n):
                if grid[i][j]==1:
                    maxArea = max(maxArea, self.getArea(grid,i,j))
        
        return maxArea
        