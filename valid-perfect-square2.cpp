// 367. Valid Perfect Square
// Given a positive integer num, write a function which returns True if num is a perfect square else False.

// Note: Do not use any built-in library function such as sqrt.

// Example 1:

// Input: 16
// Output: true

// Example 2:

// Input: 14
// Output: false


class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<=0)  return false;
        int i=1,j=num/2+1;
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            int temp=num/mid;
            if(temp==mid&&num%mid==0)  return true;
            if(temp>=mid)   i=mid+1;
            else if(temp<mid)  j=mid-1;
        }
        return false;
    }
};