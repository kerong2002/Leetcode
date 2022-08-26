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
    vector<vector<int>> answer;
    void preorder(TreeNode *root,int depth){
        if(root==NULL){
            return;
        }
        if(answer.size()==depth){
            answer.resize(depth+1);
        }
        answer[depth].push_back(root->val);
        preorder(root->left,depth+1);
        preorder(root->right,depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        preorder(root,0);
        return answer;
    }
};