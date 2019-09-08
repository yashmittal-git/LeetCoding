// 637. Average of Levels in Binary Tree
// Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

// Example 1:

// Input:
//     3
//    / \
//   9  20
//     /  \
//    15   7
// Output: [3, 14.5, 11]
// Explanation:
// The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].

// Note:

//     The range of node's value is in the range of 32-bit signed integer.


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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)   return {};
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            double x=0;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                x+=curr->val;
                if(curr->left)  q.push(curr->left);
                if(curr->right)  q.push(curr->right);
                q.pop();
            }
            ans.push_back(x/size);
        }
        return ans;
    }
};