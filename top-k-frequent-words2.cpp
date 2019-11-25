// 692. Top K Frequent Words
// Given a non-empty list of words, return the k most frequent elements.

// Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

// Example 1:
// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
//     Note that "i" comes before "love" due to a lower alphabetical order.
// Example 2:
// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// Output: ["the", "is", "sunny", "day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
//     with the number of occurrence being 4, 3, 2 and 1 respectively.
// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Input words contain only lowercase letters.
// Follow up:
// Try to solve it in O(n log k) time and O(n) extra space.


class Solution {
    struct compare{
        bool operator()(pair<string,int> p1,pair<string,int> p2){
            if(p1.second==p2.second){
                return p1.first<p2.first;
            }
            else{
                return p2.second<p1.second;
            }
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mymap;
        for(int i=0;i<words.size();i++){
            mymap[words[i]]++;
        }
        priority_queue<pair<string,int>,vector<pair<string,int>>,compare> pq;
        unordered_map<string,int>::iterator it=mymap.begin();
        for(it;it!=mymap.end();it++){
            pq.push(pair<string,int>(it->first,it->second));
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string> ans;
        while(!pq.empty()){
            ans.insert(ans.begin(),pq.top().first);
            pq.pop();
        }
        return ans;
    }
};