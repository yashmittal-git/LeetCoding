//  Given a binary tree, find the leftmost value in the last row of the tree.

// Example 1:

// Input:

//     2
//    / \
//   1   3

// Output:
// 1

// Example 2:

// Input:

//         1
//        / \
//       2   3
//      /   / \
//     4   5   6
//        /
//       7

// Output:
// 7

// Note: You may assume the tree (i.e., the given root node) is not NULL. 

// 513. Find Bottom Left Tree Value


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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr;
        while(!q.empty()){
            curr=q.front();
            q.pop();
            if(curr->right) q.push(curr->right);
            if(curr->left)  q.push(curr->left);
        }
        return curr->val;
    }
};