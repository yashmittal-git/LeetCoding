// 20. Valid Parentheses
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.

// Example 1:

// Input: "()"
// Output: true
// Example 2:

// Input: "()[]{}"
// Output: true
// Example 3:

// Input: "(]"
// Output: false
// Example 4:

// Input: "([)]"
// Output: true
// Output: false
// Example 5:

// Input: "{[]}"


class Solution {
public:
    bool check(char opening,char closing)
    {
        if(opening=='('&&closing==')') return true;
        else if(opening=='{'&&closing=='}') return true;
        else if(opening=='['&&closing==']') return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> temp;
        int i=0;
        for(i=0;i<s.length();i++)
        {   if(s[i]=='('||s[i]=='{'||s[i]=='[')
                temp.push(s[i]);
         else if(s[i]==')'||s[i]=='}'||s[i]==']')
         {
             if(temp.empty()||!check(temp.top(),s[i]))
                 return false;
             else if(check(temp.top(),s[i]))
                       temp.pop();
         }
         else return false;
        }
        if(temp.empty())
            return true;
         return false;
    }
};
