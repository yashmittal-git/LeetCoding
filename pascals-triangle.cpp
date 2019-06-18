// 118. Pascal's Triangle
// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


// In Pascal's triangle, each number is the sum of the two numbers directly above it.

// Example:

// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        if(numRows==0)  return triangle;
        triangle.push_back({1});
        for(int i=1;i<numRows;i++)
        {   vector<int> row;
            vector<int> prev=triangle[i-1];
            row.push_back(1);
            for(int j=1;j<i;j++)
                row.push_back(prev[j-1]+prev[j]);
            row.push_back(1);
            triangle.push_back(row);
        }
        return triangle;
    }
};