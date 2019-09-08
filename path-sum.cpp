// 112. Path Sum
// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

// Note: A leaf is a node with no children.

// Example:

// Given the below binary tree and sum = 22,

//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \      \
// 7    2      1

// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.


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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)    
            return 0;
        if(!root->right&&!root->left&&!(sum-root->val))    
            return 1;
        if(root->left)  
            if(hasPathSum(root->left,sum-root->val))
                return 1;
        if(root->right)  
            if(hasPathSum(root->right,sum-root->val))
                return 1;
        return 0;
    }
};