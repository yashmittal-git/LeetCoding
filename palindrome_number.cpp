class Solution {
public:
    bool isPalindrome(int x) {
       if(x<0||(x%10==0 && x!=0))
           return false;
        int y=0;
        while(x>y)
        {
            y=y*10+(x%10);
            x=x/10;
        }
        if(y==x||x==(y/10))
            return true;
        return false;
    }
};
