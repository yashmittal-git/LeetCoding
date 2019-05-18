// 171. Excel Sheet Column Number
// Given a column title as appear in an Excel sheet, return its corresponding column number.

// For example:

//     A -> 1
//     B -> 2
//     C -> 3
//     ...
//     Z -> 26
//     AA -> 27
//     AB -> 28 
//     ...
// Example 1:

// Input: "A"
// Output: 1
// Example 2:

// Input: "AB"
// Output: 28
// Example 3:

// Input: "ZY"
// Output: 701


class Solution {
public:
    int titleToNumber(string s) {
        int result=0;
        int i=0, a=1, len=s.size();
        if(len==1)
            return number(s[0]);
        for(i=0;i<len;i++){
            a=1;
            a=a*pow(26,len-i-1)*number(s[i]);
            result+=a;
        }
        return result;
    }
    
    int number(char ch)
    {   return ch-'A'+1;
    }
};


//Submission 2 After simplification
// class Solution {
// public:
//     int titleToNumber(string s) {
//         int result=0;
//         int i=0, a=1, len=s.size();
//         for(i=0;i<len;i++){
//             a=1;
//             a=a*pow(26,len-i-1)*(s[i]-'A'+1);
//             result+=a;
//         }
//         return result;
//     }
// };

//Submission 3 After further simplification
// class Solution {
// public:
//     int titleToNumber(string s) {
//         int result=0;
//         int i=0, len=s.size();
//         for(i=0;i<len;i++){
//             result+=pow(26,len-i-1)*(s[i]-'A'+1);
//         }
//         return result;
//     }
// };