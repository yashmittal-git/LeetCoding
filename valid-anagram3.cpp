// 242. Valid Anagram
// Given two strings s and t , write a function to determine if t is an anagram of s.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:

// Input: s = "rat", t = "car"
// Output: false

// Note:
// You may assume the string contains only lowercase alphabets.

// Follow up:
// What if the inputs contain unicode characters? How would you adapt your solution to such case?

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mymap;
        if(s.size()!=t.size())
            return 0;
        for(int i=0;i<s.size();i++){
            mymap[s[i]]++;
            mymap[t[i]]--;
        }
        for(auto it=mymap.begin();it!=mymap.end();it++){
            if(it->second!=0)   return 0; 
        }
        return 1;
    }
};