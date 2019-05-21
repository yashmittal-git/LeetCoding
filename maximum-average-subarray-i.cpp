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
        vector<int> sum;
        sum.resize(nums.size());
        sum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            sum[i]=sum[i-1]+nums[i];
        double avg=sum[k-1]*1.0/k;
        for(int i=k;i<nums.size();i++)
            if((sum[i]-sum[i-k])*1.0/k>avg)
                avg=(sum[i]-sum[i-k])*1.0/k;
        return avg;
    }
};