// 128. Longest Consecutive Sequence
// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

// Your algorithm should run in O(n) complexity.

// Example:

// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.


class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,bool> nums;
        for(int i=0;i<arr.size();i++){
            nums[arr[i]]=false;
        }
        int length=0;
        int start,currStart;
        int currLength=0;
        unordered_map<int,bool>::iterator it=nums.begin();
        for(int i=0;i<n;i++){
            it=nums.find(arr[i]);
            if(it->second==false){
                unordered_map<int,bool>::iterator it2;
                int currStart=it->first,currLength=1;
                it2=it;
                it2->second=true;
                while(nums.find(it2->first+1)!=nums.end()){
                    currLength++;
                    it2=nums.find(it2->first+1);
                    it2->second=true;
                }
                it2=it;
                while(nums.find(it2->first-1)!=nums.end()){
                    currLength++;
                    currStart--;
                    it2=nums.find(it2->first-1);
                    it2->second=true;
                }
                if(currLength>length){
                    length=currLength;
                    start=currStart;
                }
            }
        }
        return length;
    }
};