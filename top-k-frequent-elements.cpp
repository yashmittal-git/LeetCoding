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
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mymap;
        for(int s:nums)
            mymap[s]++;
        vector<int> arr;
        for(auto it=mymap.begin();it!=mymap.end();it++)
            arr.push_back(it->second);
        sort(arr.begin(),arr.end(),greater<int>());
        
        vector<int> ans;
        for(int i=0;i<k;i++)
        {   for(auto it=mymap.begin();it!=mymap.end();it++)
            {   if(it->second==arr[i])
                {   ans.push_back(it->first);
                    it->second=0;
                    goto here;
                }
            }
         here:;
        }
        return ans;
    }
};