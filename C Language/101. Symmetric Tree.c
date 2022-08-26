/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool check(struct TreeNode *Left,struct TreeNode *Right){
    if(!Right&&!Left){
        return true;
    }
    if(!(Right&&Left)){
        return false;
    }
    if(Left->val==Right->val){
        return check(Left->left,Right->right) && check(Left->right, Right->left);
    }
    else{
        return false;
    }
    
}
bool isSymmetric(struct TreeNode* root){
    if(root==NULL) return true;
    return check(root->left,root->right);
}