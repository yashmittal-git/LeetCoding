// 643. Maximum Average Subarray I
// Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

// Example 1:

// Input: [1,12,-5,-6,50,3], k = 4
// Output: 12.75
// Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 

// Note:

// 1 <= k <= n <= 30,000.
// Elements of the given array will be in the range [-10,000, 10,000].

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len=nums.size();
        for(int i=1;i<len;i++)
            nums[i]+=nums[i-1];
        double avg=nums[k-1]*1.0/k;
        for(int i=k;i<len;i++)
            if((nums[i]-nums[i-k])*1.0/k>avg)
                avg=(nums[i]-nums[i-k])*1.0/k;
        return avg;
    }
};