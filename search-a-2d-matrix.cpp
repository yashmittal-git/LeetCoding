// 74. Search a 2D Matrix
// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// Example 1:

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
// Example 2:

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()||!matrix[0].size())   return 0;
        
        if(matrix[0][0]>target)    return 0;
        
        for(int i=0;i<matrix.size();i++)
            if(matrix[i][0]>target)
                return binarysearch(matrix[i-1],target);
        
        if(matrix[matrix.size()-1][matrix[0].size()-1]>=target)  
            return binarysearch(matrix[matrix.size()-1],target);  
        
        return 0;
    }
    bool binarysearch(vector<int> a,int target)
    {
        int start=0,end=a.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(a[mid]==target)  return 1;
            else if(a[mid]>target)  end=mid-1;
            else if(a[mid]<target)  start=mid+1;
        }
        return 0;
    }
    
};