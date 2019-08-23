// 238. Product of Array Except Self
// Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

// Example:

// Input:  [1,2,3,4]
// Output: [24,12,8,6]

// Note: Please solve it without division and in O(n).

// Follow up:
// Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0]=1;
        right[n-1]=1;
        for(int i=0,j=1;j<n;i++){
            left[j]=left[j-1]*nums[i];
            right[n-j-1]=right[n-j]*nums[n-i-1];
            j++;
        }
        for(int i=0;i<n;i++){
            nums[i]=left[i]*right[i];
        }
        return nums;
    }
};