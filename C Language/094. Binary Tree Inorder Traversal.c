/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorder(struct TreeNode *root,int *list,int *index){
    if(root!=NULL){
        inorder(root->left,list,index);
        list[(*index)++]=root->val;
        inorder(root->right,list,index);
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *list=(int *)calloc(101,sizeof(int));
    *returnSize=0;
    inorder(root,list,returnSize);
    return list;
}