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
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i1=0,i2=0;
        vector<int> res;
        while(i1<nums1.size()&&i2<nums2.size())
        {
            if(nums1[i1]==nums2[i2])
            {
                res.push_back(nums1[i1]);
                i1++;i2++;
            }
            else if(nums1[i1]>nums2[i2])
                i2++;
            else i1++;
            while(i1>0&&i1<nums1.size()&&nums1[i1]==nums1[i1-1]) i1++;
            while(i2>0&&i2<nums2.size()&&nums2[i2]==nums2[i2-1]) i2++;
        }
        return res;
    }
};