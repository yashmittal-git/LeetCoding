// 113. Path Sum II
// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// Note: A leaf is a node with no children.

// Example:

// Given the below binary tree and sum = 22,

//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1

// Return:

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]



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
    vector<vector<int>> res;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)
            return res;
        helper({},root,sum);
        return res;
    }
    void helper(vector<int> path,TreeNode* root,int sum){
        if(!root)
            return;
        if(!root->left&&!root->right&&!(sum-root->val)){
            path.push_back(root->val);
            res.push_back(path);
            return;
        }
            path.push_back(root->val);
            helper(path,root->left,sum-root->val);
            helper(path,root->right,sum-root->val);
    }
};