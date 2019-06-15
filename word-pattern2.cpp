// 290. Word Pattern
// Given a pattern and a string str, find if str follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

// Example 1:

// Input: pattern = "abba", str = "dog cat cat dog"
// Output: true
// Example 2:

// Input:pattern = "abba", str = "dog cat cat fish"
// Output: false
// Example 3:

// Input: pattern = "aaaa", str = "dog cat cat dog"
// Output: false
// Example 4:

// Input: pattern = "abba", str = "dog dog dog dog"
// Output: false
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        if(!pattern.size()||!str.size()) return 0;
        
        int i=0,space=0;
        for(int i=0;i<str.size();i++)
            if(str[i]==' ') 
                space++;
        if(space!=pattern.size()-1) return 0;
        
        map<char,string> mymap;
        int j=0,k=0;
        i=0;
        for(i=0;i<pattern.size();i++)
        {   string word;
            while(str[j]!=' '&&j!=str.size())j++;
            word=str.substr(k,j-k);
            j++;k=j;
            
            if(mymap.count(pattern[i]))    
            {   if(mymap[pattern[i]]!=word)
                    return false;}
            else mymap.insert({pattern[i],word});
            
            auto it=mymap.begin();
            while(it!=mymap.end())
            {   if(it->second==word)
                    {if(it->first!=pattern[i])
                        return false;}
                it++;
            }
        }   
        return 1;
    }
};