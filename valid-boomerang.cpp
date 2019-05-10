// 1037. Valid Boomerang
// A boomerang is a set of 3 points that are all distinct and not in a straight line.

// Given a list of three points in the plane, return whether these points are a boomerang.

 

// Example 1:

// Input: [[1,1],[2,3],[3,2]]
// Output: true
// Example 2:

// Input: [[1,1],[2,2],[3,3]]
// Output: false
 

// Note:

// points.length == 3
// points[i].length == 2
// 0 <= points[i][j] <= 100


class Solution {
public:
    bool isBoomerang(vector<vector<int>>& a) {
        //y=mx+c;
        //checking if slopes are equal or not
        if(a[0]==a[1]||a[1]==a[2]||a[0]==a[2])
            return false;
        if((a[1][1]-a[0][1])*(a[2][0]-a[1][0])==(a[2][1]-a[1][1])*(a[1][0]-a[0][0]))
            return false;
        return true;
    }
};