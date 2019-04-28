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
        for(unsigned int i=0;i<=num;i++)
        {   unsigned int x=i*i;
            if(x==num) return true;
            else if(x>num) return false;
        }
        return false;
    }
};
