// 107. Binary Tree Level Order Traversal II
// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7

// return its bottom-up level order traversal as:

// [
//   [15,7],
//   [9,20],
//   [3]
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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)   return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                level.push_back(curr->val);
                if(curr->left)  q.push(curr->left);
                if(curr->right) q.push(curr->right);
                q.pop();
            }
            ans.push_back(level);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};