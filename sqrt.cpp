class Solution {
public:
    int mySqrt(int x) {
        for(unsigned int i=0;i<=x;i++)
        { unsigned int y=i*i;
         if(y==x) return i;
         else if(y>x)   return (i-1);
        }
        return 0;
    }
};
