// 349. Intersection of Two Arrays
// Given two arrays, write a function to compute their intersection.

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Note:

// Each element in the result must be unique.
// The result can be in any order.


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(!nums1.size()||!nums2.size())    return {};
        set<int> set1(nums1.begin(),nums1.end());
        set<int> set2(nums2.begin(),nums2.end());
        auto it1=set1.begin(),it2=set2.begin();
        vector<int> res;
        while(it1!=set1.end()&&it2!=set2.end())
        {
            if(*it1==*it2)
            {
                res.push_back(*it1);
                it1++;
                it2++;
            }
            else if(*it1>*it2)
                it2++;
            else it1++;
        }
        return res;
    }   
};