// 350. Intersection of Two Arrays II
// Given two arrays, write a function to compute their intersection.

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Note:

// Each element in the result should appear as many times as it shows in both arrays.
// The result can be in any order.
// Follow up:

// What if the given array is already sorted? How would you optimize your algorithm?
// What if nums1's size is small compared to nums2's size? Which algorithm is better?
// What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(!nums1.size()||!nums2.size())    return {};
        map<int,int> map1;
        map<int,int> map2;
        int i1=0,i2=0;
        while(i1!=nums1.size()&&i2!=nums2.size())
        {
            map1[nums1[i1++]]++;
            map2[nums2[i2++]]++;
        }
        while(i1!=nums1.size())
        {
            map1[nums1[i1++]]++;
        }
        while(i2!=nums2.size())
        {
            map2[nums2[i2++]]++;
        }
        vector<int> ans;
        auto it1=map1.begin(),it2=map2.begin();
        while(it1!=map1.end()&&it2!=map2.end())
        {
            if(it1->first==it2->first)
            {   for(int i=0;i<min(it1->second,it2->second);i++)
                    ans.push_back(it1->first);
                it1++;it2++;    
            }
            else if(it1->first>it2->first)
                it2++;
            else it1++;
        }
        return ans;
    }
};