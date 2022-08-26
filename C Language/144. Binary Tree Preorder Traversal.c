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
void preorder(struct TreeNode* root,int *list,int *index){   //前序
    if(root!=NULL){
        list[(*index)++]=root->val;
        preorder(root->left,list,index);
        preorder(root->right,list,index);
    }
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int *list=(int *)calloc(104,sizeof(int));
    *returnSize=0;
    preorder(root,list,returnSize);
    return list;
}