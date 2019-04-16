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
