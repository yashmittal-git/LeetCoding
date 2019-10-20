// 200. Number of Islands
// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input:
// 11110
// 11010
// 11000
// 00000

// Output: 1

// Example 2:

// Input:
// 11000
// 11000
// 00100
// 00011

// Output: 3

class Solution {
    int area(int r,int c,vector<vector<bool>>& seen,vector<vector<char>>& grid){
        if(r<0||r>grid.size()-1||c<0||c>grid[0].size()-1||seen[r][c]||grid[r][c]=='0')
            return 0;
        seen[r][c]=1;
        return (1+area(r-1,c,seen,grid)+area(r,c-1,seen,grid)+area(r,c+1,seen,grid)+area(r+1,c,seen,grid));    
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size())
            return 0;
        vector<vector<bool>> seen;
        seen=vector<vector<bool>>(grid.size(),vector<bool>(grid[0].size(),0));
        int ans=0;
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(area(r,c,seen,grid))
                    ans++;
            }
        }
        return ans;
    }
};