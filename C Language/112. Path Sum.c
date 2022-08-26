/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool search(struct TreeNode *root,int targetSum){
    if(root==NULL){
        return false;
    }
    targetSum-=root->val;
    if(targetSum==0 && root->left==NULL && root->right==NULL){
        return true;
    }
    return (search(root->left,targetSum)||search(root->right,targetSum));
}
bool hasPathSum(struct TreeNode* root, int targetSum){
    // if(root==NULL) return false;
    return search(root,targetSum);
}