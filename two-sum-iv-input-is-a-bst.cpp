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
        return helper(root,root,k);
    }
    bool helper(TreeNode* root,TreeNode* curr,int k){
        if(!curr)
            return false;
        int target=k-curr->val;
        if(search(root,curr,target))
            return true;
        return helper(root,curr->left,k)||helper(root,curr->right,k);
    }
    bool search(TreeNode* root,TreeNode*curr,int target){
        if(!root)
            return false;
        if(root==curr&&root->val==target)
            return search(root->left,curr,target);
        if(root->val==target)
            return true;
        if(target<root->val)
            return search(root->left,curr,target);
        else
            return search(root->right,curr,target);
    }
};