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
        vector<int> dp(tls,0);
        dp[0]=triangle[0][0];
        cout<<dp[0]<<" "<<endl;
        for(int i=1;i<ts;i++){
            dp[i]=triangle[i][i]+dp[i-1];
            cout<<dp[i]<<" ";
            for(int j=i-1;j>0;j--){
                dp[j]=min(dp[j-1],dp[j])+triangle[i][j];
                cout<<dp[j]<<" ";
            }
            dp[0]+=triangle[i][0];
            cout<<dp[0]<<" ";
            cout<<endl;
        }
        int min=dp[0];
        for(int i=1;i<tls;i++){
            if(dp[i]<min)
                min=dp[i];
        }
        return min;
    }
};
