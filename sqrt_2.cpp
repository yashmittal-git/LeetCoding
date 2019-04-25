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
