// 451. Sort Characters By Frequency
// Given a string, sort it in decreasing order based on the frequency of characters.

// Example 1:

// Input:
// "tree"

// Output:
// "eert"

// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input:
// "cccaaa"

// Output:
// "cccaaa"

// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input:
// "Aabb"

// Output:
// "bbAa"

// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.


class Solution {
public:
    string frequencySort(string s) {
        map<char,int>   mymap;
        for(int i=0;i<s.size();i++)
            mymap[s[i]]++;
        
        vector<int> arr;
        for(auto it=mymap.begin();it!=mymap.end();it++)
           arr.push_back(it->second);
        sort(arr.begin(),arr.end(),greater<int>());
        
        string ans;
        for(int i=0;i<arr.size();i++)
            for(auto it=mymap.begin();it!=mymap.end();it++)
            {   if(it->second==arr[i])
                {   while(it->second>0)
                    {
                        ans.push_back(it->first);
                        it->second--;
                    }
                }
            }
        return ans;
    }
};