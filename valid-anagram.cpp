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
        if(s.size()!=t.size())  return 0;
        map<char,int> map;
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
            map[t[i]]--;
        }
        for(auto it=map.begin();it!=map.end();it++)
            if(it->second!=0)    return false;
        return 1;
    }
};