// 120. Triangle
// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

// For example, given the following triangle

// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]

// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

// Note:

// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()||triangle[0].empty())
            return 0;
        int ts=triangle.size(),tls=triangle[ts-1].size();
        vector<vector<int>> dp(ts,vector<int>(tls,0));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<ts;i++){
            dp[i][0]=triangle[i][0]+dp[i-1][0];
            dp[i][i]=triangle[i][i]+dp[i-1][i-1];
            for(int j=1;j<i;j++){
                dp[i][j]=triangle[i][j]+min(dp[i-1][j-1],dp[i-1][j]);
            }
        }
        int min=dp[tls-1][0];
        for(int i=1;i<tls;i++){
            if(dp[tls-1][i]<min)
                min=dp[tls-1][i];
        }
        return min;
    }
    
};
