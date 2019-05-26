// 541. Reverse String II
// Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
// Example:
// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"
// Restrictions:
// The string consists of lower English letters only.
// Length of the given string and k will in the range [1, 10000]


class Solution {
public:
    string reverseStr(string s, int k) {
        for(int x=0;x<s.size();x+=2*k)
        {
            int i=x,j;
            if(x+k-1>=s.size())
                j=s.size()-1;
            else j=x+k-1;
            while(i<j){
                if(s[i]!=s[j]){
                s[i]=s[i]^s[j];
                s[j]=s[i]^s[j];
                s[i]=s[i]^s[j];
            }
            i++;
            j--;
        }
        }
        return s;
    }
};