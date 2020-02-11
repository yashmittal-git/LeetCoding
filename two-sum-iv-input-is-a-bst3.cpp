// 653. Two Sum IV - Input is a BST
// Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

// Example 1:

// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Target = 9

// Output: True

 

// Example 2:

// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Target = 28

// Output: False


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
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root,arr);
        return search(arr,k);
    }
    bool search(vector<int>& arr,int k){
        int i=0,j=arr.size()-1;
        while(i<j){
            if(arr[i]+arr[j]==k)
                return true;
            if(arr[i]+arr[j]<k)
                i++;
            else j--;
        }
        return false;
    }
    void inorder(TreeNode* root,vector<int>& arr){
        if(!root)
            return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
};