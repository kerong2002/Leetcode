/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(vector<string>& ans, TreeNode* root, string put){
        if(!root->left && !root->right){
            ans.push_back(put + to_string(root->val));
        }
        else{
            if(root->left){
                dfs(ans, root->left, put + to_string(root->val) + "->");
            }
             if(root->right){
                dfs(ans, root->right, put + to_string(root->val) + "->");
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root){
            dfs(ans, root, "");
        }
        return ans;
    }
};