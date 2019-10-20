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
    vector<string> res={};
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)   return {};
        if(!root->left&&!root->right)   return {to_string(root->val)};
        vector<int> s;
        dfs(root,s);
        return res;
    }
    void dfs(TreeNode* root,vector<int> s){
        if(!root->left&&!root->right){
            s.push_back(root->val);
            string str;
            int i=0;
            for(i=0;i<s.size()-1;i++){
                str+=to_string(s[i]);
                str+="->";
            }
            str+=to_string(s[i]);
            res.push_back(str);
        }
        if(root->left){
            s.push_back(root->val);
            dfs(root->left,s);
            s.pop_back();
        }
        if(root->right){
            s.push_back(root->val);
            dfs(root->right,s);
            s.pop_back();
        }
    }
};