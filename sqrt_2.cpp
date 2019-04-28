// 69. Sqrt(x)
// Implement int sqrt(int x).

// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

// Example 1:

// Input: 4
// Output: 2
// Example 2:

// Input: 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since 
//              the decimal part is truncated, 2 is returned.


class Solution {
public:
    int mySqrt(int x) {
        if(x==1||x==0)
            return x;
        unsigned long int start=1, end=x/2;
        unsigned long int y,mid,ans;
        while(start<=end)
        {   
            mid=start+(end-start)/2;
            y=mid*mid;
            if(y==x) return mid;
            else
                if(y>x) end=mid-1;
            else
                if(y<x)
                {
                    start=mid+1;
                    ans=mid;
                }
        }
        return ans;
    }
};
