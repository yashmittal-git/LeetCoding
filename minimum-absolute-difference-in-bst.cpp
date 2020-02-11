// 530. Minimum Absolute Difference in BST
// Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

// Example:

// Input:

//    1
//     \
//      3
//     /
//    2

// Output:
// 1

// Explanation:
// The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).

 

// Note: There are at least two nodes in this BST.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> arr;
        inorder(arr,root);
        int min=arr[arr.size()-1]-arr[0];
        for(int i=1;i<arr.size();i++){
            min=minimum(min,arr[i]-arr[i-1]);
        }
        return min;
    }
    void inorder(vector<int>& arr,TreeNode*root){
        if(!root)
            return;
        inorder(arr,root->left);
        arr.push_back(root->val);
        inorder(arr,root->right);
    }
    int minimum(int a,int b){
        return a>b?b:a;
    }
};  