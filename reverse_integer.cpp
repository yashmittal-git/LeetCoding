class Solution {
public:
    int reverse(int n) {
        long int ans=0;
        while(n!=0)
        {   int y=n%10;
            n=n/10;
            ans=ans*10+y;
            if(ans>INT_MAX||ans<INT_MIN)
                return 0;
        }
        return ans;
    }
    
};
