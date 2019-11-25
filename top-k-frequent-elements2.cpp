// 347. Top K Frequent Elements
// Given a non-empty array of integers, return the k most frequent elements.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
// Note:

// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

class Solution {
    struct compare{
        bool operator()(pair<int,int> p1,pair<int,int> p2){
            return p2.second<p1.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mymap;
        for(int i=0;i<nums.size();i++){
            mymap[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        unordered_map<int,int>::iterator it=mymap.begin();
        
        for(it;it!=mymap.end();it++){
            pq.push(pair<int,int>(it->first,it->second));
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};