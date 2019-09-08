// 103. Binary Tree Zigzag Level Order Traversal
// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

// For example:
// Given binary tree [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7

// return its zigzag level order traversal as:

// [
//   [3],
//   [20,9],
//   [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)   return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        int z=0;
        while(!q.empty()){
            vector<int> level;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left)  q.push(curr->left);
                if(curr->right) q.push(curr->right);
                if(z%2==0)
                    level.push_back(curr->val);
                else 
                    level.insert(level.begin(),curr->val);
            }
            ans.push_back(level);
            z++;
        }
        return ans;
    }
};