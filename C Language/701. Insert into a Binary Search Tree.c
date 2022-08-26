/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if(root==NULL){
        struct TreeNode *new=(struct TreedNode *)malloc(sizeof(struct TreeNode));
        new->val=val;
        new->left=NULL;
        new->right=NULL;
        return new;
    }
    if(root->val<val){
        root->right=insertIntoBST(root->right,val);
    }
    else{
        root->left=insertIntoBST(root->left,val);
    }
    return root;
}