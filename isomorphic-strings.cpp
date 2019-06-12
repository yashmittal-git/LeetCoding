// 205. Isomorphic Strings
// Given two strings s and t, determine if they are isomorphic.

// Two strings are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

// Example 1:

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
// Example 3:

// Input: s = "paper", t = "title"
// Output: true
// Note:
// You may assume both s and t have the same length.



class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return check(s,t)&&check(t,s);
    }
    bool check(string s, string t)
    {   map<char,char> mymap;
        for(int i=0;i<s.size();i++)
        {   if(!mymap[s[i]])
                mymap[s[i]]=t[i];
            else if(mymap[s[i]]!=t[i])
                return 0;
        }
        return 1;
    }
};