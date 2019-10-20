// 257. Binary Tree Paths
// Given a binary tree, return all root-to-leaf paths.

// Note: A leaf is a node with no children.

// Example:

// Input:

//    1
//  /   \
// 2     3
//  \
//   5

// Output: ["1->2->5", "1->3"]

// Explanation: All root-to-leaf paths are: 1->2->5, 1->3

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root)
            preorder(res,"",root);
        return res;
    }
    void preorder(vector<string>& res,string s,TreeNode* root){
        if(!root)
            return;
        if(s.empty()){
            s+=to_string(root->val);
        }
        else{
            s=s+"->"+to_string(root->val);
        }
        if(root->left)
            preorder(res,s,root->left);
        if(root->right)
            preorder(res,s,root->right);
        if(!root->left&&!root->right){
            res.push_back(s);
        }
    }
};