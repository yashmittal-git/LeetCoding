// 695. Max Area of Island
// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

// Example 1:

// [[0,0,1,0,0,0,0,1,0,0,0,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,1,1,0,1,0,0,0,0,0,0,0,0],
//  [0,1,0,0,1,1,0,0,1,0,1,0,0],
//  [0,1,0,0,1,1,0,0,1,1,1,0,0],
//  [0,0,0,0,0,0,0,0,0,0,1,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,0,0,0,0,0,0,1,1,0,0,0,0]]

// Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

// Example 2:

// [[0,0,0,0,0,0,0,0]]

// Given the above grid, return 0.

// Note: The length of each dimension in the given grid does not exceed 50.


class Solution {
    int area(int r,int c,vector<vector<bool>>& seen,vector<vector<int>>& grid){
        if(r<0||r>grid.size()-1||c<0||c>grid[0].size()-1||seen[r][c]||!grid[r][c])
            return 0;
        seen[r][c]=1;
        return (1+area(r-1,c,seen,grid)+area(r,c-1,seen,grid)+area(r,c+1,seen,grid)+area(r+1,c,seen,grid));    
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> seen;
        seen=vector<vector<bool>>(grid.size(),vector<bool>(grid[0].size(),0));
        int ans=0;
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                ans=max(ans,area(r,c,seen,grid));
            }
        }
        return ans;
    }
};