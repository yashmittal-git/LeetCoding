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
    struct compare{
        bool operator ()(const pair<char,int>& p1,const pair<char,int>& p2){
            return p2.second>p1.second;
        }
    };
public:
    string frequencySort(string s) {
        unordered_map<char,int> mymap;
        for(int i=0;i<s.size();i++){
            mymap[s[i]]++;
        }
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare> pq;
        for(unordered_map<char,int>::iterator it=mymap.begin();it!=mymap.end();it++){
            pq.push(pair<char,int>(it->first,it->second));
        }
        string ans="";
        while(!pq.empty()){
            for(int i=0;i<pq.top().second;i++){
                ans+=pq.top().first;
            }
            pq.pop();
        }
        return ans;
    }
};