// 977. Squares of a Sorted Array
// Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

 

// Example 1:

// Input: [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Example 2:

// Input: [-7,-3,2,3,11]
// Output: [4,9,9,49,121]
 

// Note:

// 1 <= A.length <= 10000
// -10000 <= A[i] <= 10000
// A is sorted in non-decreasing order.


class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int N=A.size();
        int i=0;
        while(i<N&&A[i]<0)
            i++;
        int j=i-1;
        int t=0;
        vector<int> ans=A;
        while(j>=0&&i<N){
            if(A[i]*A[i]>A[j]*A[j])
            {
                ans[t]=A[j]*A[j];
                t++;j--;
            }
            else{
                ans[t]=A[i]*A[i];
                t++;i++;
            }
        }
        while(j>=0){
            ans[t]=A[j]*A[j];
                t++;j--;
        }
        while(i<N){
            ans[t]=A[i]*A[i];
            t++;i++;
        }
        return ans;
    }
};