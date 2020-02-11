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
        unordered_set<int> myset;
        return find(myset,root,k);
    }
    bool find(unordered_set<int>& myset,TreeNode* root, int k){
        if(!root)
            return false;
        if(myset.find(k-root->val)!=myset.end())
            return true;
        myset.insert(root->val);
        return find(myset,root->left,k)||find(myset,root->right,k);            
    }
};