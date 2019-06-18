119. Pascal's Triangle II
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?



class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows=rowIndex+1;
        vector<vector<int>> triangle(numRows);
        for(int i=0;i<numRows;i++)
            for(int j=0;j<=i;j++)
            {
                if(j==0||j==i)  triangle[i].push_back(1);
                else
                    triangle[i].push_back(triangle[i-1][j-1]+triangle[i-1][j]);
            }
        return triangle[rowIndex];
    }
};